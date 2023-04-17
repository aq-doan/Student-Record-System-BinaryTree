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

// Definition of a singly linked list node struct with an integer data field and a pointer to the next node.
typedef struct listNode {
	BST student_id;
	String unit_name;
	struct listNode* next;
}*ListNodePtr; // Alias for pointer to struct listNode

// Definition of a singly linked list struct with a pointer to the head node.
typedef struct list {
	ListNodePtr head;
} List;

// Function to create and return a new empty list.
List new_list();

// Function to insert a new node with given data in the list in ascending order.
void insert_in_order(List* self, String data);

// Function to print the contents of a list.
void print_list(List* self);

// Function to insert a new node with given data at the front of the list.
void insert_at_front(List* self, String data);


// Function to delete the first occurrence of a node with given data from the list.
void delete_from_list(List* self, String data);

// Function to free the memory allocated to a list and all its nodes.
void destroy_list(List* self);
