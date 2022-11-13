#include <stdio.h>
#include <stdlib.h>
#include "arr.h"


int *array_input(int *len){
	printf("Number of elements: ");
	scanf("%d", len);
	int *data = (int*)malloc(*len * sizeof(int));
	if (!data) {
		printf("Failed to allocate memory\n");
		return NULL;
	}
	for (int i = 0; i < *len; ++i){
		printf("Element at index %d: ", i);
		scanf("%d", &data[i]);
	}
	return data;
}


void input_element(int **arr, int *len){
	int index;
	int value = 3;
	printf("Enter index and value: "); 
	while(scanf("%d%d", &index, &value) !=2 || *len+index <=0){
			printf("Wrong type!\n");
			scanf("%*[^\n]");
		}
	if (index < 0){
		index += *len;
	}
	*len+=1;
	*arr = (int*)realloc(*arr, (*len)*sizeof(int));
	if (index > *len-2){
		*(*arr + *len-1) = value;
	}
	else{
		for(int i=*len-1; i>index; i--){
			*(*arr + i) = *(*arr + i - 1);
		}
		*(*arr + index) = value;
	}
	printf("\nThe array is: ");
	for(int i = 0; i<*len; i++){
		printf("%d, ", *(*arr + i));
	}
	printf("\n");
}


void remove_element(int **arr, int *len){
	int index;
	printf("Enter index: ");
	while(scanf("%d", &index) !=1 || *len+index <= 0){
		printf("Wrong type!\n");
		scanf("%*[^\n]");
	}
	if (index < 0){
		index += *len;
	}
	for (int i = index; i < *len - 1; i++){
		*(*arr + i) = *(*arr + i + 1);
	}
	*len-=1;
	printf("\nThe array is: ");
	for(int i = 0; i<*len; i++){
		printf("%d, ", *(*arr + i));
	}
	printf("\n");
}
