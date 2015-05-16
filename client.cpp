//
/// \file client.cpp
/// \author James Marlowe
/// \brief Functions related to interacting with aerospike
//

#include <string>
#include <iostream>
#include <aerospike/aerospike.h>
#include <aerospike/aerospike_key.h>
#include <aerospike/as_error.h>
#include <aerospike/as_record.h>
#include <aerospike/as_status.h>

std::string get_cache(aerospike &as, std::string &snamespace, std::string &sset, std::string &skey, std::string &sbin)
{
    as_error err;

    //Initialize Key
    as_key key;
    as_key_init(&key, snamespace.c_str(), sset.c_str(), skey.c_str());

    //Read from database
    as_record* p_rec = NULL;
    static const char* select[] = { sbin.c_str(), NULL };
    if (aerospike_key_select(&as, &err, NULL, &key, select, &p_rec) != AEROSPIKE_OK) {
        fprintf(stderr, "err(%d) %s at [%s:%d]\n", err.code, err.message, err.file, err.line);
    }
    //char * value = as_record_get_str(p_rec, bin);
    as_record_destroy(p_rec);
    return value;
}

void set_cache(aerospike &as, std::string &snamespace, std::string &sset, std::string &skey, std::string &sbin, std::string &svalue)
{
    as_error err;
    
    //Initialize Key
    as_key key;
    as_key_init(&key, snamespace.c_str(), sset.c_str(), skey.c_str());
    
    //Initialize Record Data
    as_record rec;
    as_record_inita(&rec, 1);
    as_record_set_str(&rec, sbin, svalue.c_str());

    //Write to Database
    if (aerospike_key_put(&as, &err, NULL, &key, &rec) != AEROSPIKE_OK) {
        fprintf(stderr, "err(%d) %s at [%s:%d]\n", err.code, err.message, err.file, err.line);
    }
}

int main ()
{
    //Configure the Client
    as_config config;
    as_config_init(&config);
    config.hosts[0] = { .addr = "127.0.0.1", .port = 3000 };
    
    //Initialize a Client
    aerospike as;
    aerospike_init(&as, &config);
    
    //Establish a Connection
    as_error err;
    if (aerospike_connect(&as, &err) != AEROSPIKE_OK) {
        fprintf(stderr, "err(%d) %s at [%s:%d]\n", err.code, err.message, err.file, err.line);
    }
    
    // set a value
    set_cache(as, "test", "seconds", "test_key", "time", "1234");
    
    // set a value
    std::string value = get_cache(as, "test", "seconds", "test_key", "time");
    
    return 0;
}
