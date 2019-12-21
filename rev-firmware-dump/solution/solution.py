#!/usr/bin/python3

from pwn import *
import binascii

context.log_level = 'debug'

"""
Solution:
    Binary devtty contains an XOR encrypted "firmware" which is a cat_flag
    ELF file encoded in base64. base64 will have repeating "A" characters so xortool
    can be used to get the password.

    The password is used to login to the devtty binary and also used to decrypt the 
    firmware in memory. Once the password is obtained, the binary
    can be parsed from memory dump via the provided session or just dumped from gdb.
    Finally, run the obtained ELF file to get the flag.

        https://github.com/hellman/xortool

    xortool firmware
    xortool -l 16 -c "A" firmware
        1 possible key(s) of length 16:
        'th1s1sn0tth3fl@g

    Hint is to provide players with knowledge that it is xor encryption so they can
    conduct XOR crypto breaking attacks.

    or

    Get password hash from binary.
    Crack the SHA1() hash 
    "\x24\xd7\x71\x64\x40\x39\x69\x2c\x60\xf2\x7a\x49\x2e\x51\x22\x2e\xe5\x4c\xd8\xc2"

    Probably not doable though, hashcat says time to crack is 42mins + 3 days + 311 days
    if given password length and the first half of the password.

"""
def parse_hex_str_from_line(line):
    line.split(b" ")
    hex_str = ""
    for digits in line:
        if digits == 124:
            break
        if digits == 32:
            continue
        hex_str += chr(digits)

    print(line)
    binary_string = binascii.unhexlify(hex_str)
    return binary_string

def main():
    target = process("./devtty")

    print(target.recvuntil(b"Username:"))
    target.sendline(b"root")

    print(target.recvuntil(b"Password:"))
    target.sendline(b"th1s1sn0tth3fl@g")

    print(target.recvuntil(b">"))
    offset = 0
    firmware_size = 16616

    out_file = open("out_file", "wb")

    for i in range(0, firmware_size, 16):
        command = b"dumphex " + str(i).encode("utf-8") + b" 16"
        target.sendline(command)
        hexdump = target.recvline()
        target.recvuntil(b"> ")
        lines = hexdump.split(b"\n")
        for line in lines:
            out_file.write(parse_hex_str_from_line(line))

if __name__ == "__main__":
    main()

# utc{y0u_g0t_th3_f1rmw@r3_!}
