/*
* NOTE: This file is an adaptation of the learning material of the University of Tasmania
* KIT205, produced by Robert Ollington
* The intial code can be found in the following page
* https://mylo.utas.edu.au/d2l/le/content/566489/viewContent/4972074/View
* This version is modified by Anh Quan Doan for the first Assignment of KIT205
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
#include "linkedlist.h"
#include"binary_search_tree.h"
#include <time.h>
#include <math.h>

#define MIN 0
#define MAX 7


//function to ask for the id of the student and return it as an integer
int ask_id() {
	int id_ask;
	printf("Enter id:\n ");
	scanf("%ld", &id_ask);
	return id_ask;
}

//function to ask for the c
String ask_unit() {
	char buffer[100];

	printf("Enter unit: \n");
	scanf("%s", buffer);

	String unit_ask = malloc(sizeof(char) * (strlen(buffer) + 1));
	strcpy(unit_ask, buffer);

	return unit_ask;
}

void menu(List* list_of_unit, int input) {
	int id_courses_student_enrol;
	int count_student;
	int id;
	String unit;
	ListNodePtr temp;
	String unenrol_unit;
	int id_unenrol;
	ListNodePtr temp_unenrol;
	String specific_unit;
	ListNodePtr temp_specific;
	ListNodePtr current_courses_student_enrol;
	ListNodePtr current;
	switch (input) {
	case 1:
		id = ask_id();
		unit = ask_unit();
		if (search_list(list_of_unit, unit) == NULL) {
			insert_in_order(list_of_unit, unit);
		}
		temp = search_list(list_of_unit, unit);
		insert_bst(&temp->student_list, id);

		break;

	case 2:
		unenrol_unit = ask_unit();
		id_unenrol = ask_id();
		temp_unenrol = search_list(list_of_unit, unenrol_unit);
		delete_bst(&temp_unenrol->student_list, id_unenrol);
		break;


	case 3:
		specific_unit = ask_unit();

		temp_specific = search_list(list_of_unit, specific_unit);

		print_in_order_bst(&temp_specific->student_list);
		break;

	case 4:
		id_courses_student_enrol = ask_id();

		current_courses_student_enrol = list_of_unit->head;
		while (current_courses_student_enrol != NULL)
		{
			if (find_bst_node(&current_courses_student_enrol->student_list, id_courses_student_enrol))
			{
				printf("%s\n", current_courses_student_enrol->unit_name);
			}
			current_courses_student_enrol = current_courses_student_enrol->next;
		}
		break;
	case 5:

		current = list_of_unit->head;

		while (current != NULL)
		{
			count_student = count_node(&current->student_list);
			printf("%s %d\n", current->unit_name, count_student);
			current = current->next;
		}
		break;
	}
}



void main() {
	List list_of_unit = create_list();
	int input;

	do {
		//display menu
		printf("\n");
		printf("Please pick an option(1-5). if you want to to exit pick 0.\n");
		printf("1. Enrol a student in a unit\n");
		printf("2. Un-enrol a student from a unit\n");
		printf("3. Print an ordered list of students enrolled in a specific unit\n");
		printf("4. Print an ordered list of units that a specific student is enrolled in\n ");
		printf("5. Print an ordered summary of all units and the number of students enrolled in each\n");
		printf("0. Quit the application\n");
		printf("Enter your option:\n");
		do {
			scanf("%d", &input); //read input
		} while (input < MIN || input > MAX);
		menu(&list_of_unit, input); //process the option
	} while (input != 0); //quit
	if (list_of_unit.head != NULL) {

		destroy_list(&list_of_unit);
	}
	/*
	BST tree = new_bst();
	clock_t start = clock();
	for (int i = 0; i < 20000000; i++)
	{
		int a = rand();
		insert_bst(&tree, i);
	}

	clock_t diff = clock() - start;
	long msec = diff * 1000 / CLOCKS_PER_SEC;
	
	printf("Operation took %d milliseconds\n\n", msec);
	*/
}


void test_list() {
	List list = create_list();

	// insert some nodes into the list
	insert_in_order(&list, "KIT111");
	insert_in_order(&list, "KIT205");
	insert_in_order(&list, "KIT222");

	// print the list
	printf("List contents: ");



	ListNodePtr node = search_list(&list, "KIT205");
	if (node != NULL) {
		printf("search list success");
	}
	else {
		printf("search list failed\n");
	}

	// delete a node from the list
	delete_list(&list, "KIT205");
	ListNodePtr current = (&list)->head;

	while (current != NULL)
	{
		int count_student = count_node(&current->student_list);
		printf("%s %d\n", current->unit_name, count_student);
		current = current->next;
	}
	//test destroy
	destroy_list(&list);
}
void test_bst() {
	
	BST bst = new_bst();

	//insert directly into the bst
	insert_bst(&bst, 5);
	insert_bst(&bst, 3);
	insert_bst(&bst, 7);
	insert_bst(&bst, 1);
	insert_bst(&bst, 4);
	insert_bst(&bst, 6);
	insert_bst(&bst, 8);
	printf("Test count node in BST: %d\n", count_node(&bst));
	printf("test print in order:\n");
	print_in_order_bst(&bst);

	BSTNodePtr node1 = find_bst_node(&bst, 5);
	if (node1 != NULL) {
		printf("find node success.\n");
	}
	else {
		printf("find node fail\n");
	}
	BSTNodePtr node2 = find_bst_node(&bst, 2);
	if (node2 != NULL) {
		printf("find node success.\n");
	}
	else {
		printf("find node fail\n");
	}

	delete_bst(&bst, 4);
	printf("Expect no 4 in the bst.\n");
	delete_bst(&bst, 7);
	printf("Expect no 7 in the bst.\n");
	print_in_order_bst(&bst); //pass if no 4 and 7 in the bst

	destroy_bst(&bst);
	if (&bst == NULL) { //if the list is empty
		printf("destroy_bst sucess.\n");
	}
	else {
		printf("destroy_bst failed.\n");
	}
}