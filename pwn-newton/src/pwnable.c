#include <stdio.h>
#include <stdlib.h>


char *pages[5];
char *chapter_name;
size_t page_lengths[5];
size_t curr_page = 0;

long get_choice() {
    char choice[0x20];
    read(0, choice, 0x20);
    choice[sizeof(choice) - 1] = 0;
    return atol(choice);
}

void set_page(size_t sz) {
    puts("What do you want to write?");
    if(sz > 0x20) {
        sz = 0x20;
    }
    page_lengths[curr_page] = sz;
    read(0, pages[curr_page++], sz);

}

void add_page() {
    puts("How many characters is this page?");
    size_t sz = get_choice();
    char *page = malloc(sz);
    pages[curr_page] = page;
    set_page(sz);
}


void read_page() {
    puts("Which page do you want to read?");
    size_t page_num = get_choice();
    if(page_num < 0 || page_num >= 5) {
        puts("Invalid page number!");
        exit(1);
    }

    if(pages[page_num] == 0) {
        puts("You haven't written in this page yet!");
        exit(1);
    }

    write(1, pages[page_num], page_lengths[page_num]);
    //puts(pages[page_num]);
}

void delete_page() {
    puts("Which page do you want to delete?");
    size_t page_num = get_choice();
    if(page_num < 0 || page_num >= 5) {
        puts("Invalid page number!");
        exit(1);
    }

    if(pages[page_num] == 0) {
        puts("You haven't written in this page yet!");
        exit(1);
    }
    free(pages[page_num]);
}

void name_chapter() {
    if(chapter_name != NULL) {
        puts("You already named this chapter!");
        return;
    }
    puts("What would you like to name this chapter?");
    chapter_name = malloc(30);
    read(0, chapter_name, 50);
}

void init() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void prompt() {
    puts("[1] Add New Page");
    puts("[2] View Page");
    puts("[3] Delete Page");
    puts("[4] Name chapter");
    puts("[5] Exit");
    write(1, ">", 2);
}

int main() {
    init();
    puts("Ohayou Sir Isaac Newton!");
    while(curr_page < 6) {
        prompt();
        long choice = get_choice();
        switch(choice) {
        case 1:
            add_page();
            break;
        case 2:
            read_page();
            break;
        case 3:
            delete_page();
            break;
        case 4:
            name_chapter();
            break;
        case 5:
            return 0;
        default:
            puts("Invalid Option!");
        }
    }
    return 0;
}
