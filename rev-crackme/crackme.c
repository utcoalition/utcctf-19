#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *str) {
  while (*str) {
    if (*str >= 'A' && *str <= 'Z') 
      *str = (*str - 'A' + 5) % 26 + 'A';
    else if (*str >= 'a' && *str <= 'z') 
      *str = (*str - 'a' + 5) % 26 + 'a';
    str++;
  }
}

const char *key = "L33TC0dE";
void encrypt2(char *str) {
  int i = 0;
  while (str[i]) {
    str[i] ^= key[i % 8];
    i++;
  }
}

const char *life = "\x78\x01\x12\x0b\x77\x02\x45\x1a\x78\x01\x12\x0b\x77\x02\x45\x64\x6d\x02\x02\x75\x62\x01\x45";
int main() {
  int num = 0;
  char word[16];
  char word2[32];
  char *tmp;

  puts("What is your favorite number?");
  if (scanf("%d", &num) != 1) {
    puts("Nope! Bye!");
    return 1;
  }

  // SHOULD BE 383
  if (num != rand() % 1000) {
    puts("No that's a bad number!");
    return 1;
  }

  puts("What word am I thinking of...?");
  scanf("%16s", word);
  getchar();
  tmp = strdup(word);
  encrypt(tmp);
  //EsREvER!
  if (strcmp(tmp, "JxWJaJW!")) {
    puts("Nope!");
    return 1;
  }

  puts("What is the meaning to life?");
  fgets(word2, sizeof(word2), stdin);
  strtok(word2, "\n");
  tmp = strdup(word2);
  // 42!_42!_42!_42!!!11!!1!
  encrypt2(tmp);
  if (strcmp(tmp, life)) {
    puts("Nope!");
    return 1;
  }

  printf("Good. Your flag is utc{%d_%s_%s}!\n", num, word, word2);
  return 0;
}

