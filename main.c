#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include"binary_search_tree.h"


int main() {
	//create a new list to store the courses
	List unit_list = new_list();
	String unit_name = NULL;
	char buffer[100];
	int id = 0;

	//Variable to store the use input
	int command =0;
	int user_input = 0;
	while (command == 0)
	{
		//menu option
		printf("Choose a number from (1-6) to select operation: \n");
		printf("1. Enrol a student in a unit\n");
		printf("2. Un-enrol a student from a unit\n");
		printf("3. Print an ordered list of students enrolled in a specific unit\n");
		printf("4. Print an ordered list of units that a specific student is enrolled in\n");
		printf("5. Print an ordered summary of all units and the number of students enrolled in each \n");
		printf("6. Quit the application\n");

		//store the input
		scanf_s("%d", &user_input);
		if (user_input != 6) {
			//processing the user option
			switch (user_input)
			{
			case 1: //case for enrolling the unit
				//get student id
				printf("Enter student id for enrolling: \n");
				scanf("%d", &id);

				//get unit name
				printf("Enter unit name to enrol: \n");
				scanf_s("%s", buffer, 100);

				//store unit name in list
				unit_name = malloc(sizeof(char) * (strlen(buffer) + 1));
				strcpy(unit_name, buffer);
				

				//store student id
				ListNodePtr find_unit = find_list(&unit_list, unit_name);
				if (find_unit == NULL) {
					insert_in_order(&unit_list, unit_name);
				}
				insert_bst(&find_unit->student_id, id);

				break;
			case 2: //case for unenrolling
				//get unit name
				printf("Enter unit name of the student: \n");
				scanf_s("%s", buffer, 100);

				printf("Enter student id for unenrolling: \n");
				scanf("%d", &id);

				//find the unit 
				ListNodePtr finding_unit = find_list(&unit_list, unit_name);
				if (finding_unit !=NULL)
				{
					delete_bst(&finding_unit->student_id, id);
				}
				else {
					printf("Error: unit not found\n!");
				}
				
				break;
			case 3:
				//get unit name
				printf("Enter unit name: \n");
				scanf_s("%s", buffer, 100);
				unit_name = malloc(sizeof(char) * (strlen(buffer) + 1));
				strcpy(unit_name, buffer);
				ListNodePtr course = find_list(&unit_list, unit_name);
				print_in_order_bst(&course->student_id);

				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				user_input = 6;
				break;
			default:
				printf("Error!\n");
				break;
			}
		}
		else {
			command = 1;
		}
	}
	destroy_list(&unit_list);
	return 0;
}