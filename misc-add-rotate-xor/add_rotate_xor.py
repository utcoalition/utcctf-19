#!/usr/bin/env python

import random
import os
import sys

sys.stderr = None

ROUNDS = 15

print """
Welcome to Add Rotate Xor Game
Solve {} rounds to get the Flag.

In each round you'll be given a permutation of numbers from 0 to 255, and you'll have to perform some steps to convert a sorted permutation (0..255) to the given permutation.

You're allowed three operations:
1) 0 x, 0 <= x < 256, Adds x to each number in the array modulo 256.
2) 1 x, 0 <= x < 8, Rotate left each number in the array by x.
3) 2 x, 0 <= x < 256, Xor each number by x.

Source code of operations for clarity:

m = range(256)
for a, b in fin_ans:
    for i in range(256):
        tmp = m[i]
        if a==0:
            tmp=(tmp+b)&0xff
        elif a==1:
            tmp=((tmp>>(8-b))|(tmp<<b))&0xff
        elif a==2:
            tmp=tmp^b
        m[i] = tmp

You must solve each round in <= 2500 operations.

Enter each operation as: `id x`, where id is 0, 1 or 2.

=======================================================

""".format(ROUNDS)


flag = 'utc{4dd1ng_and_x0ring_unt1l_1_c4nt_4nymor3._.!!}'
rounds_solved = 0

for r in range(ROUNDS):
    print "ROUND {}".format(r+1)
    print ""
    random.seed(os.urandom(32))
    perm = range(256)
    random.shuffle(perm)
    print " ".join(map(str, perm))
    print ""
    print "Enter the number of operations followed by the operations, one per line."
    n = int(raw_input().strip())
    if n > 2500:
        print "Operation count too high"
        break
    ops = []
    for i in range(n):
        line = raw_input().strip().split()
        ops.append([int(line[0]), int(line[1])])

    m = range(256)
    for a, b in ops:
        for i in range(256):
            tmp = m[i]
            if a==0:
                tmp=(tmp+b)&0xff
            elif a==1:
                tmp=((tmp>>(8-b))|(tmp<<b))&0xff
            elif a==2:
                tmp=tmp^b
            m[i] = tmp
    if m == perm:
        rounds_solved += 1
        print "Correct!"
    else:
        print "Wrong!"
        break

if rounds_solved == ROUNDS:
    print flag
