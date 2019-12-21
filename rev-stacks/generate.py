import os
import random
flag = "utc{stAcks_Ar3_WACK!!!_HEHEXDXD}"


key = [ch for ch in os.urandom(len(flag))]


check = [ord(c1) ^ c2 for c1,c2 in zip(flag,key)]


def gen_junk():
    if random.randint(0,4) == 0:
        #hehe xd
        length = random.randint(1,20)
        print("dq junk")
        print(f"dq {hex(length)}")
        junk = ",".join([hex(random.randint(0,255)) for _ in range(length)])
        print(f"db {junk}")


print(key)
#print(len(key))

for i in check:
    gen_junk()
    print("dq deref_rsi_rax")
    gen_junk()
    print("dq deref_rdi_rbx")
    gen_junk()
    print("dq xor_rbx")
    print(f"dq {hex(i)}")
    gen_junk()
    print("dq check")
    gen_junk()
    print("dq inc_rsi")
    gen_junk()
    print("dq inc_rdi\n")
    gen_junk()

