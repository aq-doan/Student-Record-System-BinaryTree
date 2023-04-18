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

/*
Create a new instance of the list type
*/
List create_list();

/*
Insert a new element in an ordered list
*/
void insert_in_order(List* self, String data);

/**
*Traverse the link-list to find the 'target' course.
*/
ListNodePtr search_list(List* self, String data);

/*
Delete an item from a list
*/
void delete_list(List* self, String data);


/*
 Delete all items in a list
 */
void destroy_list(List* self);

