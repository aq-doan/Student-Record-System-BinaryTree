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


List new_list() {
	List temp;
	temp.head = NULL;
	return temp;
}

// after changing to char*:
// -- need to change printf for string
void print_list(List* self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		printf("%s", current->unit_name);
		current = current->next;

		if (current != NULL)
			printf(", ");
	}
	printf("\n");
}
// Function to insert a new node with given data in the list in ascending order.
void insert_in_order(List* self, String data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;
	int str_length = strlen(data) + 1; //finding the data's length

	ListNodePtr new_node = malloc(sizeof * new_node);
	new_node->unit_name = malloc((str_length) * sizeof * new_node->unit_name); //allocate memory based on data's length
	strcpy(new_node->unit_name, data);//copy string

	
	new_node->next = NULL;
	new_node->student_id.root = NULL;

	while (current != NULL && strcmp(current->unit_name,data) < 0) {
		prev = current;
		current = current->next;
	}

	if (current == self->head) { // at front
		new_node->next = current;
		self->head = new_node;
	}
	else {                     // middle
		new_node->next = current;
		prev->next = new_node;
	}
}

// after changing to char*:
// -- check how long data parameter is (strlen)
// -- allocate just enough memory for newNode->data (malloc)
// -- copy string from parameter into newNode->data (strcpy)
void insert_at_front(List* self, String data) {
	//variable
	int str_length = strlen(data) + 1; //finding the data's length
	ListNodePtr new_node = malloc(sizeof * new_node);

	new_node->unit_name = malloc((str_length) * sizeof * new_node->unit_name); //allocate memory based on data's length
	strcpy(new_node->unit_name, data);//copy string

	new_node->next = self->head;
	self->head = new_node;
}
//find a unit name from the user input through traversal
ListNodePtr find_list(List* self, String data) {
	ListNodePtr current_node = self->head;
	ListNodePtr prev = NULL;
	ListNodePtr result = NULL; //return variable

	

	while (current_node != NULL)
	{
		if (strcmp(current_node->unit_name, data) == 0)
		{
			result = current_node;
		}
		else {
			current_node = current_node->next;
		}

	}
	return result;
}
// after changing to char*:
// -- change test in if statement to string compare (strcmp)
// -- free current->data (memory allocated for string) before freeing current
void delete_from_list(List* self, String data) {
	ListNodePtr current_node = self->head;
	ListNodePtr prev = NULL;
	int compare = strcmp(current_node->unit_name, data);
	ListNodePtr unit = current_node->unit_name;

	while (current_node != NULL) {
		if (compare == 0) {
			if (prev == NULL) {        // front of list
				self->head = current_node->next;
				destroy_bst(&current_node->student_id);//free bst memory
				free(current_node->unit_name);
				unit = NULL;
				free(current_node);
				current_node = self->head;
			}
			else {                    // middle of list
				prev->next = current_node->next;
				free(current_node->unit_name);
				unit = NULL;
				free(current_node);
				current_node = prev->next;
				destroy_bst(&current_node->student_id); //free bst memory
			}
		}
		else {
			prev = current_node;
			current_node = current_node->next;
		}
	}
}

// after changing to char*:
// -- need to free memory allocated for string before freeing node
void destroy_list(List* self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		ListNodePtr to_free = current;

		current = current->next;
		free(to_free->unit_name);
		free(to_free);
	}
	self->head = NULL;
}

