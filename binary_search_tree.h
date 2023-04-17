
/*
* NOTE: This file is an adaptation of the learning material of the University of Tasmania
* KIT205, produced by Robert Ollington
* The intial code can be found in the following page
* https://mylo.utas.edu.au/d2l/le/content/566489/viewContent/4972074/View
* This version is modified by Anh Quan Doan for the first Assignment of KIT205
*/
#pragma once
/**
 * @struct bstNode
 * @brief Represents a single node in a binary search tree
 *
 * Contains an integer data item and pointers to its left and right children.
 */
typedef struct bstNode {
	int student_id;
	struct bstNode* left;
	struct bstNode* right;
} *BSTNodePtr;

/**
 * @struct bst
 * @brief Represents a binary search tree
 *
 * Contains a pointer to the root node of the BST.
 */
typedef struct bst {
	BSTNodePtr root;
} BST;

/**
 * @brief Creates a new, empty binary search tree
 *
 * @return The new binary search tree
 */
BST new_bst();

/**
 * @brief Finds a node with a given data item in a binary search tree
 *
 * @param self Pointer to the binary search tree to search
 * @param n The data item to search for
 *
 * @return Pointer to the node with the given data item, or NULL if it is not found
 */
BSTNodePtr find_bst(BST* self, int n);

/**
 * @brief Inserts a node with a given data item into a binary search tree
 *
 * @param self Pointer to the binary search tree to insert into
 * @param n The data item to insert
 */
void insert_bst(BST* self, int n);

/**
 * @brief Deletes a node with a given data item from a binary search tree
 *
 * @param self Pointer to the binary search tree to delete from
 * @param n The data item to delete
 */
void delete_bst(BST* self, int n);

/**
 * @brief Prints the data items of a binary search tree in ascending order
 *
 * @param self Pointer to the binary search tree to print
 */
void print_in_order_bst(BST* self);

/**
 * @brief Frees all memory allocated for a binary search tree
 *
 * @param self Pointer to the binary search tree to destroy
 */
void destroy_bst(BST* self);

/**
*@brief to test the binary search tree
*
*/
void bst_test();

/**
*@brief Prints the data items of a binary search tree in pre order
*
*@param self Points to the binary search tree to print
*/
void print_pre_order_bst(BST* self);

/**
*@brief Prints the data items of a binary search tree in post order
*
*@param self Points to the binary search tree to print
*/
void print_pre_order_bst(BST* self);

/**
* A function to calculate the height of a bst and return the height in integer
*/
int height_bst(BST* self);