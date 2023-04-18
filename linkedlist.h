/*
* NOTE: This file is an adaptation of the learning material of the University of Tasmania
* KIT205, produced by Robert Ollington
* The intial code can be found in the following page
* https://mylo.utas.edu.au/d2l/le/content/566489/viewContent/4956911/View
* This version is modified by Anh Quan Doan for the first Assignment of KIT205
*/
#pragma once 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "binary_search_tree.h"
typedef char* String;

typedef struct listNode {
	String unit_name;
	BST student_list;
	struct listNode* next;
} *ListNodePtr;

typedef struct list {
	ListNodePtr head;
} List;

//function to intialise a list
List create_list();

//function to insert an element in order
void insert_in_order(List* self, String data);

//function to delete an item 
void delete_list(List* self, String data);


//function to free memory when not used
void destroy_list(List* self);

//function to search a target node in the list
ListNodePtr search_list(List* self, String data);
