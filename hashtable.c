// hashtable_wk5.c
#include <stdlib.h>
#include "hashtable.h"

HashTable create_hashtable(int n) {
	HashTable newtable;

	// TODO: allocate memory for array and init lists
	newtable.size = n;
	newtable.table = malloc(n * sizeof(List));
	for (int i = 0; i < n; i++) {
		newtable.table[i] = new_list();//create new list for each row
	}

	return newtable;
}

int hash(String key, int size) {
	unsigned long h = 0; // unsigned long, so that when it wraps it's still positive
	int n = strlen(key);

	for (int i = 0; i < n; i++) {
		// multiply by 32 (<<5) and add ascii value
		h = (h << 5) + (int)(key[i]);
	}
	return h % size;
}

void hash_insert(HashTable* self, String key) {
	
	int row = 0;
	// 1. find the list to insert into using hash
	row = hash(key, self->size);

	// 2. call list function to insert into that list
	insert_at_front(&(self->table[row]), key);
}

void hash_remove(HashTable* self, String key) {
	int i = hash(key, self->size);//get the key
	delete_from_list(&self->table[i], key); //delete

}

void hash_print(HashTable* self) {
	for (int i = 0; i < self->size; i++) {
		printf("%d: ", i);
		print_list(&(self->table[i]));
	}
}

void hash_destroy(HashTable* self) {
	// TODO
	// iterate over each bucket in the table
	for (int i = 0; i < self->size; i++) {
		destroy_list(&(self->table[i]));// destroy the list in the bucket
	}
	// free the memory allocated for the table itself
	free(self->table);
}