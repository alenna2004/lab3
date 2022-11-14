#include <stdio.h>
#include <stdlib.h>
#include "arr.h"
#include "wrap.h"


void print_arr(int **arr, int *len){
	for(int i = 0; i<*len; i++){
		printf("%d, ", *(*arr + i));
	}
	printf("\n");
}


void input_element_wrap(int **arr, int *len){
	int index;
	int value;
	printf("Enter index and value: "); 
	while(scanf("%d%d", &index, &value) !=2 || *len+index <=0){
			printf("Wrong type!\n");
			scanf("%*[^\n]");
		}
	if (index < 0){
		index += *len;
	}
	input_element(index, value, arr, len);
	print_arr(arr, len);

}

void remove_element_wrap(int **arr, int *len){
	int index;
	printf("Enter index: ");
	while(scanf("%d", &index) !=1 || *len+index <= 0){
		printf("Wrong type!\n");
		scanf("%*[^\n]");
	}
	if (index < 0){
		index += *len;
	}
	if (index >= *len){
		index = *len-1;
	}
	remove_element(index, arr, len);
	print_arr(arr, len);
}