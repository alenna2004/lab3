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


void input_element(int index, int value, int **arr, int *len){
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
}


void remove_element(int index, int **arr, int *len){
	for (int i = index; i < *len - 1; i++){
		*(*arr + i) = *(*arr + i + 1);
	}
	*len-=1;
}
