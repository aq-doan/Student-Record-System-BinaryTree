
#pragma once

#include "linkedlist.h"

typedef struct hashTable {
	int size;
	List* table;
} HashTable;

HashTable create_hashtable(int n);

int hash(String key, int size);

void hash_insert(HashTable* self, String key);

void hash_remove(HashTable* self, String key);

void hash_print(HashTable* self);

void hash_destroy(HashTable* self);