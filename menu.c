#include <stdio.h>
#include <stdlib.h>
#include "arr.h"

void print_menu(){
	printf("Choose what to do and enter the appropriate number:\n");
	printf("1. Create an array\n");
	printf("2. Input an element by its index in the array\n");
	printf("3. Remove an element by its index from the array\n");
	printf("4. Process the array\n");
	printf("5. Quit\n");

}


int main(void){
	int var = 0;
	int len_ar;
	int *point_to_arr = NULL;
	while(var !=5){
		print_menu();
		while(scanf("%d", &var) != 1 || var > 5 || var < 1){
			printf("Wrong type! Enter another value\n");
			scanf("%*[^\n]");
		}
		switch(var){
			case 1:{
				if(point_to_arr){
					free(point_to_arr);
				}
				point_to_arr = array_input(&len_ar);
				break;
			}
			case 2:{
				if(point_to_arr){
					input_element(&point_to_arr, &len_ar);
				}
				else{
					printf("Create the array first!\n");
				}
				break;
			}
			case 3:{
				if(point_to_arr){
					remove_element(&point_to_arr, &len_ar);
				}
				else{
					printf("Create the array first!\n");
				}
				break;
			}
			case 4:{
				process_arr(&point_to_arr, &len_ar);
				break;
			}
			case 5:{
				free(point_to_arr);
				break;
			}
		}
	}
	return 0;
}
