#include <stdio.h>
#include "GroceryList.h"

Entry grocery_list[20]; // Start with a value of 20
int size = 0; // Amount of items in list

int main(){
    char * function, item;
    int amount;

    while(1) { // Loop until EOF is input
        printf("Please add or remove an item (all lowercase):\n");
        int scan_result = scanf("%s %s %d", &function, &item, &amount);

        if (feof(stdin)) {
            printf("Your grocery list:\n");
            //print list

            printf("Goodbye!\n");
            break;
        }

        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF); // Clear the buffer

        if (scan_result != 3) {
            fprintf(stderr, "Input must contain 3 arguments.\n\n");
            continue;
        }

        if (function != "add" && function != "remove") {
            fprintf(stderr, "Invalid function name.\n\n");
            continue;
        }

        if (function == "add") {
            //add
        } else if (function == "remove") {
            //remove
        }
    }

    return 0;
}

void add(Entry * entry) {
    //Unimplemented
}

void remove(char * item) {
    //Unimplemented
}

void print_list() {
    //Unimplemented
}