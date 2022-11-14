#include <stdio.h>
#include <stdlib.h>
#include "arr.h"
#include "wrap.h"

void print_menu(){
	printf("Choose what to do and enter the appropriate number:\n");
	printf("1. Create an array\n");
	printf("2. Input an element by its index in the array\n");
	printf("3. Remove an element by its index from the array\n");
	printf("4. Process the array\n");
	printf("5. Quit\n");

}

void check_input(int *var){
	while(scanf("%d", var) != 1 || *var > 5 || *var < 1){
		printf("Wrong type! Enter another value\n");
		scanf("%*[^\n]");
	}
}

void print_arr_alt(){
	printf("Choose the array\n");
	printf("1. Processed array\n");
	printf("2. New array\n");
}


int main(void){
	int var = 0;
	int len_ar;
	int *point_to_arr = NULL;
	int *new_arr = NULL;
	int new_len = 0;
	while(var !=5){
		print_menu();
		check_input(&var);
		switch(var){
			case 1:{
				if(point_to_arr){
					free(point_to_arr);
				}
				point_to_arr = array_input(&len_ar);
				break;
			}
			case 2:{
				if (new_arr){
					int opt = 0;
					print_arr_alt();
					check_input(&opt);
					switch(opt){
						case 1:{
							input_element_wrap(&point_to_arr, &len_ar);
							break;
						}
						case 2:{
							input_element_wrap(&new_arr, &new_len);
							break;
						}
					}
					break;
				}
				else{
					if(point_to_arr){
						input_element_wrap(&point_to_arr, &len_ar);
					}
					else{
						printf("Create the array first!\n");
					}
					break;
				}
			}
			case 3:{
				if (new_arr){
					int opt = 0;
					print_arr_alt();
					check_input(&opt);
					switch(opt){
						case 1:{
							remove_element_wrap(&point_to_arr, &len_ar);
							break;
						}
						case 2:{
							remove_element_wrap(&new_arr, &new_len);
							break;
						}
					}
					break;
				}
				else{
					if(point_to_arr){
						remove_element_wrap(&point_to_arr, &len_ar);
					}
					else{
						printf("Create the array first!\n");
					}
					break;
				}
			}
			case 4:{
				if (new_arr){
					int opt = 0;
					print_arr_alt();
					check_input(&opt);
					switch(opt){
						case 1:{
							free(new_arr);
							new_arr = NULL;
							new_len = 0;
							new_arr = process_arr(&point_to_arr, &len_ar, &new_len);
							break;
						}
						case 2:{
							point_to_arr = (int*)realloc(point_to_arr, new_len*sizeof(int));
							for (int i=0; i< new_len; i++){
								point_to_arr[i] = new_arr[i];
							}
							len_ar = new_len;
							free(new_arr);
							new_arr = NULL;
							new_len = 0;
							new_arr = process_arr(&point_to_arr, &len_ar, &new_len);
							break;
						}
					}
					break;
				}
				else{
					new_arr = process_arr(&point_to_arr, &len_ar, &new_len);
					break;
				}
			}
			case 5:{
				free(point_to_arr);
				free(new_arr);
				break;
			}
		}
	}
	return 0;
}
