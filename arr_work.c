#include <stdio.h>
#include <stdlib.h>
#include "arr.h"


int *array_input(int *len, int *mem_al, int N){
	printf("Number of elements: ");
	scanf("%d", len);
	int *data = (int*)malloc((((*len/N)+1)*N)*sizeof(int));
	if (!data) {
		printf("Failed to allocate memory\n");
		return NULL;
	}
	for (int i = 0; i < *len; ++i){
		printf("Element at index %d: ", i);
		scanf("%d", &data[i]);
	}
	*mem_al = ((*len/N)+1)*N;
	return data;
}


void input_element(int index, int value, int **arr, int *len, int *mem_al, int N){
	*len+=1;
	if (*mem_al <*len){
		*mem_al += N;
		*arr = (int*)realloc(*arr, (*mem_al)*sizeof(int));
	}
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


void remove_element(int index, int **arr, int *len, int *mem_al, int N){
	for (int i = index; i < *len - 1; i++){
		*(*arr + i) = *(*arr + i + 1);
	}
	*len-=1;
	if((*mem_al -(*len)) >= N){
		*mem_al -= N;
		*arr = (int*)realloc(*arr, (*mem_al)*sizeof(int));
	}
}
