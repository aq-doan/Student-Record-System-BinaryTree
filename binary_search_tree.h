#pragma once
/*
* NOTE: This file is an adaptation of the learning material of the University of Tasmania
* KIT205, produced by Robert Ollington
* The intial code can be found in the following page
* https://mylo.utas.edu.au/d2l/le/content/566489/viewContent/4972074/View
* This version is modified by Anh Quan Doan for the first Assignment of KIT205
*/


typedef struct bstNode {
	int id_number;
	struct bstNode* left;
	struct bstNode* right;
} *BSTNodePtr;

typedef struct bst {
	BSTNodePtr root;
} BST;

//function to create a new tree
BST new_bst();

//function to code the node in the tree
int count_node(BST* self);

//function to find node
BSTNodePtr find_bst_node(BST* self, int n);

//function to insert in order
void insert_bst(BST* self, int n);

//function to delete a node through traversal
void delete_bst(BST* self, int n);

//function to free memory
void destroy_bst(BST* self);

//function to print in order
void print_in_order_bst(BST* self);
