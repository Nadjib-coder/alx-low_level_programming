#!/bin/bash
wget -P /$PWD https://github.com/Nadjib-coder/alx-low_level_programming/0x18-dynamic_libraries/libtest.so
export LD_PRELOAD=/$PWD/libtest.so
