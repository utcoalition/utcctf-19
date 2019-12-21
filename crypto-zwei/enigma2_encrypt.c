#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 64

void usage() {
    printf("usage: ./enigma2_encrypt \"<message>\"\n");
    exit(1);
}

void msg2long() {
    printf("Message too long to encrypt.\n");
    exit(2);
}

void encrypt(int ord) {
    int a = rand() % 128;
    int b = rand() % 128;
    int c = ord - (a + b);
    printf("%d %d %d ", a, b, c);
}

int main(int argc, char *argv[]) {
    if (argc != 2)
        usage();
    
    srand(time(0));
    
    char msg[MAX_SIZE];
    int msgOrds[MAX_SIZE], ord;
    int i = 0;
    int size = strlen(argv[1]);
    
    if (size > MAX_SIZE)
        msg2long();
    
    strncpy(msg, argv[1], size);

    while (msg[i] != '\0') {
        ord = (int)msg[i];
        msgOrds[i] = ord;
        i++;
    }
    
    for(i=0; i<size; i++)
        encrypt(msgOrds[i]);
    printf("\n");

    return 0;
}
