#!/bin/bash
wget -P /tmp https://github.com/Nadjib-coder/alx-low_level_programming/raw/master/0x18-dynamic_libraries/lib3.so
export LD_PRELOAD=/tmp/lib3.so
