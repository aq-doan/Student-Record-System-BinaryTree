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

}
