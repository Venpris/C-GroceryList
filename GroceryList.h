typedef struct {
    char * item;
    int amount;
} Entry;

/*
* Adds an item to the list.
*
* @param entry The entry to be added to the grocery list.
*/
void add(Entry entry);

/*
* Removes an item from the list, identified by the name of the item.
*
* @param item The name of the item to be removed.
*/
void remove_item(char * item, int amount);

/*
* Prints the list created by the user. This function will be called
* right before terminating the program after the quit message is
* input by the user.
*/
void print_list();