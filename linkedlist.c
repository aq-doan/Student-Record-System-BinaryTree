/*
* NOTE: This file is an adaptation of the learning material of the University of Tasmania
* KIT205, produced by Robert Ollington
* The intial code can be found in the following page
* https://mylo.utas.edu.au/d2l/le/content/566489/viewContent/4956911/View
* This version is modified by Anh Quan Doan for the first Assignment of KIT205
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <stdbool.h>
#include <string.h>



//create new list
List create_list() {
	List temp;
	temp.head = NULL;
	return temp;
}

//function to free memory
void destroy_list(List* self) {
	ListNodePtr clist = self->head;
	while (clist != NULL) {
		ListNodePtr a = clist;

		clist = clist->next; //continue to tranverse

		destroy_bst(&a->student_list);
		free(a->unit_name);
		free(a);
	}
	self->head = NULL;
}

//function to traverse the linked list to find the data
ListNodePtr search_list(List* self, String data) {
	ListNodePtr clist = self->head;
	while (clist != NULL)
	{
		if (strcmp(clist->unit_name, data) == 0)
		{
			return clist;
		}
		else
		{
			clist = clist->next;
		}
	}
	return NULL;
}


//function to delete an item from the list
void delete_list(List* self, String data) {
	ListNodePtr clist = self->head;
	ListNodePtr plist = NULL;

	while (clist != NULL) {
		int compare = strcmp(clist->unit_name, data);
		if (compare == 0) {
			if (plist == NULL) { // front of list
				self->head = clist->next;
				destroy_bst(&clist->student_list);
				free(clist->unit_name);
				clist->unit_name = NULL;
				free(clist);
				clist = self->head;
			}
			else {// middle of list
				plist->next = clist->next;

				destroy_bst(&clist->student_list);
				free(clist->unit_name);
				clist->unit_name = NULL;
				free(clist);

				clist = plist->next;
			}
		}
		else { //if not found
			plist = clist;
			clist = clist->next;
		}
	}
}

//function to insert in order
void insert_in_order(List* self, String data) {
	ListNodePtr clist = self->head;
	ListNodePtr plist = NULL;
	ListNodePtr new_list_node = malloc(sizeof * new_list_node);

	int str_length = strlen(data) + 1; //finding the data's length
	//allocate memory based on data's length
	new_list_node->unit_name = malloc((str_length) * sizeof(String));

	//copy string
	strcpy(new_list_node->unit_name, data);

	new_list_node->student_list.root = NULL;

	new_list_node->next = NULL;

	while (clist != NULL && strcmp(clist->unit_name, data) < 0) {
		plist = clist;
		clist = clist->next;
	}

	if (clist == self->head) { // at front
		new_list_node->next = clist;
		self->head = new_list_node;
	}
	else {// middle
		new_list_node->next = clist;
		plist->next = new_list_node;
	}
}