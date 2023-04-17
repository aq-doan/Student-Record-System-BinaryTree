#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "hashtable.h"
#include"binary_search_tree.h"

int main() {
	int command = 1;
	HashTable table = create_hashtable(11);
	List strings = new_list();
	char buffer[100];

	bst_test();
	//free memory
	destroy_list(&strings);
	hash_destroy(&table);
}