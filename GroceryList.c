#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GroceryList.h"

Entry grocery_list[20]; // Start with a value of 20
int size = 0; // Amount of items in list
char line[100]; // Buffer to hold each line of input

int main(){
    char function[10], item[20];
    int amount;

    while(1) { 
        printf("Please add or remove an item (all lowercase):\n");

        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("\nYour grocery list:\n");
            print_list();

            printf("Goodbye!\n");
            break;
        }

        int scan_result = sscanf(line, "%9s %19s %d", function, item, &amount);

        if (scan_result != 3) {
            fprintf(stderr, "Input must contain 3 arguments.\n\n");
            continue;
        }

        if (strcmp(function, "add") && strcmp(function, "remove")) {
            fprintf(stderr, "Invalid function name.\n\n");
            continue;
        }

        if (strcmp(function, "add") == 0) {
            Entry entry = { .item = strdup(item), .amount = amount };
            add(entry);
            printf("\n");
        } else if (strcmp(function, "remove") == 0) {
            remove_item(item, amount);
            printf("\n");
        }
    }

    return 0;
}

void add(Entry entry) {
    grocery_list[size] = entry;
    size++;
}

void remove_item(char * item, int amount) {
    for (int i = 0; i < size; i++) {
        if (strcmp(grocery_list[i].item, item) == 0 && grocery_list[i].amount == amount) {
            free(grocery_list[i].item);
            for (int j = i; j < size - 1; j++) {
                grocery_list[j] = grocery_list[j + 1];
            }
            size--;
            return;
        }
    }

    fprintf(stderr, "Specified item and amount could not be located.\n");
}

void print_list() {
    printf("%-10s%-10s\n", "Item", "Amount");
    for (int i = 0; i < size; i++) {
        printf("%-10s%d\n", grocery_list[i].item, grocery_list[i].amount);
    }
}