#!/usr/bin/python3

import os

# After getting the key length, iterate through all common char's 0x00-0xff
# with xortool
for i in range(0, 256):
    try:
        command = "xortool -l 16 -c \"\\x%02x\" encrypted" % i
        print(command)
        response = os.popen(command).read()
        lines = response.split("\n")
        key = lines[1]
        print(key)
    except:
        pass

# xortool -l 16 -c "\x41" encrypted
# 'th1s1sn0tth3fl@g
