#include <stdio.h>
#include <stdlib.h>

int selfish = 1;

void gimme_flag() {
  int flag2 = 0xdeadbeef;
  char flag[] = "\x9a\xca\xce\xa5\x8e\xe1\xc1\xef\x9b\xca\xc1\xbb\xb0\xd6\x99\xac\x8b\x8d\xdf\x81\xd5\x97\xd0\xde";

  if (selfish) {
    puts("Don't be selfish! Share the flag with me...");
    exit(0);
  }

  for (int i = 0; i < sizeof(flag); i++) {
    flag[i] ^= ((char*)&flag2)[i % sizeof(flag2)];
  }

  puts(flag);
}

int main() {
  puts("utc{fakeflag_still}");
  selfish = 0;
//  gimme_flag();
}
