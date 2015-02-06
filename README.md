# aerospike-sample
Sample cpp project for testing a connection to an aerospike database

Requirements
------------
```
sudo apt-get install libssl0.9.8 libssl-dev liblua5.1-dev
sudo ln -s /usr/lib/x86_64-linux-gnu/liblua5.1.so /usr/lib/liblua.so
sudo ln -s /usr/lib/x86_64-linux-gnu/liblua5.1.a /usr/lib/liblua.a
wget http://www.aerospike.com/download/client/c/3.1.0/artifact/ubuntu12
tar xvzf aerospike-client-c-3.1.0.ubuntu12.04.x86_64.tgz
sudo dpkg -i aerospike-client-c-devel-3.1.0.ubuntu12.04.x86_64.deb
```

build
-----
```
git clone git@github.com:jamesmarlowe/aerospike-sample.git
cd aerospike-sample
mkdir build
cd build
cmake ..
```
