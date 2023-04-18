/*
* NOTE: This file is an adaptation of the learning material of the University of Tasmania
* KIT205, produced by Robert Ollington
* The intial code can be found in the following page
* https://mylo.utas.edu.au/d2l/le/content/566489/viewContent/4972074/View
* This version is modified by Anh Quan Doan for the first Assignment of KIT205
*/
#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

// create a new empty binary search tree
BST new_bst() {
	BST temp;
	temp.root = NULL;
	return temp;
}

// recursive function to find a value and return the containing node
BSTNodePtr search_bst_node(BSTNodePtr self, int n) {
	BSTNodePtr result = search_bst_node(self->right, n);
	if (self == NULL || n == self->id_number) {
		result = self;
	}

	if (n < self->id_number) {
		result = search_bst_node(self->left, n);
	}
	return result;

}

// find a value in the tree and return the node
BSTNodePtr search_tree(BST* self, int n) {
	return search_bst_node(self->root, n);
}


// recursive function to insert a value
BSTNodePtr insert_bst_node(BSTNodePtr self, int n) {
	
	if (self == NULL) { /* found where to put it*/
		self = malloc(sizeof * self);
		self->id_number = n;
		self->left = self->right = NULL;

	}
	else if (n < self->id_number) {
		self->left = insert_bst_node(self->left, n);
	}
	else if (n > self->id_number) {
		self->right = insert_bst_node(self->right, n);
	}

	return self;
}

// insert a value into the tree
void insert_bst(BST* self, int n) {
	self->root = insert_bst_node(self->root, n);
}



// helper function for delete this function find the smallest node in a bst branch
BSTNodePtr min_node(BSTNodePtr self) {
	BSTNodePtr c = self;

	while (c->left != NULL) {
		c = c->left;
	}
	return c;
}


// recursive function to delete a value
BSTNodePtr delete_bst_node(BSTNodePtr self, int n) {
	if (self != NULL) {
		if (self->id_number == n) {
			if (self->left != NULL && self->right != NULL) {
				// two child case 
				BSTNodePtr successor = min_node(self->right);
				self->id_number = successor->id_number;
				self->right = delete_bst_node(self->right, self->id_number);

			}
			else { // one or zero child case 
				BSTNodePtr to_free = self;
				if (self->left) {
					self = self->left;
				}
				else {
					self = self->right;
				}
				free(to_free);
			}
		}
		else if (n < self->id_number) {
			self->left = delete_bst_node(self->left, n);
		}
		else {
			self->right = delete_bst_node(self->right, n);
		}
	}
	return self;
}

// delete a value from the tree
void delete_bst(BST* self, int n) {
	self->root = delete_bst_node(self->root, n);
}


// recursive function to destroy all node
void destroy_bst_node(BSTNodePtr self) {

	if (self != NULL) {
		destroy_bst_node(self->left);
		self->left = NULL;
		destroy_bst_node(self->right);
		self->right = NULL;

		free(self);
	}
}

// destroy the tree
void destroy_bst(BST* self) {
	destroy_bst_node(self->root);
	self->root = NULL;
}

/**
* print a binary search tree using in-order format
*/
void print_in_order_bst_node(BSTNodePtr self) {
	if (self == NULL) {
		printf("_");
	}
	else {
		print_in_order_bst_node(self->left);
		printf("%d", self->id_number);
		print_in_order_bst_node(self->right);
	}
}

void print_in_order_bst(BST* self) {
	print_in_order_bst_node(self->root);
}


//count the number of node of a bst
int count_bst(BSTNodePtr self) {
	int count;
	if (self == NULL) {
		return 0;
	}
	count = 1 + count_bst(self->left) +
		count_bst(self->right);

	return count;
}

int count_node(BST* self) {
	return count_bst(self->root);
}
