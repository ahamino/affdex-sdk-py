# Python bindings for Affdex SDK


## Requirements
- Python v2.7
- virtualenv
- pybind11
- GNU GCC

## Setup

Instructions for Ubuntu 14.04

*Prepare the virtual enviroment*

```shell
sudo apt-get install python-dev python-virtualenv
virtualenv $HOME/venv
. $HOME/venv/bin/activate
pip install pybind11
```

*Download Affdex SDK for Linux*
```shell
cd $HOME
wget http://affdex-sdk-dist.s3-website-us-east-1.amazonaws.com/linux/affdex-cpp-sdk-3.0-298-linux-64bit.tar.gz
mkdir $HOME/affdex-sdk
cd $HOME/affdex-sdk
tar -xzvf $HOME/affdex-cpp-sdk-3.0-298-linux-64bit.tar.gz
```

*Compile the Python bindings*
```shell
export AFFDEX_SDK_HOME=$HOME/affdex-sdk

c++ -O3 -shared -std=c++11 -fPIC -Wl,--no-as-needed -I$AFFDEX_SDK_HOME/include \
-I$HOME/venv/include/site/python2.7 `python-config --cflags --ldflags --libs` \
-Wl,--no-as-needed -laffdex-native -L$AFFDEX_SDK_HOME/lib affdex.cpp -o affdex.so
```
