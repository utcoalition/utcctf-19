#include <stdio.h>
#include <stdlib.h>

struct song {
    char name[20];
    char *lyrics;
};

struct song mixtape[10];

long get_num() {
    char buff[0x20];
    fgets(buff, 0x20, stdin);
    return atol(buff);
}

void init() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void prompt() {
    puts("Welcome to Lil IDA's studio!");
    puts("[1] Add song");
    puts("[2] Drop mixtape");
    puts("[3] Delete song");
    puts("[4] Edit song");
    puts("[5] Exit");
    write(1, ">", 2);
}

void add_song() {
    puts("Enter a song number:");
    size_t index = get_num();
    if(index < 0 || index > 10) {
        puts("Index out of range");
        return;
    }
    puts("What would you like to name this song?");
    fgets(mixtape[index].name, 20, stdin);

    mixtape[index].lyrics = malloc(0x100);
    puts("Write the lyrics to your song:");
    fgets(mixtape[index].lyrics, 0x100, stdin);
}

void drop_mixtape() {
    puts("Lil IDA is about to drop his mixtape...");
    for(size_t i = 0; i < 10; ++i) {
        if(mixtape[i].lyrics != NULL) {
            printf("Now playing: %s", mixtape[i].name);
            puts(mixtape[i].lyrics);
        }
    }
}

void edit_song() {
    puts("Which song would you like to edit?");
    size_t index = get_num();
    if(index < 0 || index > 10) {
        puts("Index out of range");
        return;
    }

    if(mixtape[index].lyrics == NULL) {
        puts("You haven't written that song yet....");
        return;
    }
    puts("Enter the new lyrics:");
    fgets(mixtape[index].lyrics, 0x100, stdin);
}

void delete_song() {
    puts("Which song would you like to delete?");
    size_t index = get_num();
    if(index < 0 || index > 10) {
        puts("Index out of range");
        return;
    }

    if(mixtape[index].lyrics == NULL) {
        puts("You haven't written that song yet....");
        return;
    }
    free(mixtape[index].lyrics);
}


int main() {
    init();
    while(1) {
        prompt();
        long choice = get_num();
        switch(choice) {
        case 1:
            add_song();
            break;
        case 2:
            drop_mixtape();
            break;
        case 3:
            delete_song();
            break;
        case 4:
            edit_song();
            break;
        case 5:
            return 0;
        default:
            puts("Invalid Option!");
        }
    }
    return 0;
}
