#include <stdio.h>
#include <stdlib.h>
#include "arr.h"


int find_num_digit(int digit, int num){
	int res = 0;
	while (num){
		int cur_digit = num % 10;
		if (cur_digit==digit){
			res +=1;
		}
		num /= 10;
	}
	return res;
}


int get_digits(int num){
	int res = 0;
	int i = 9;
	for (i; i>0; i-=1){
		int num_digits = find_num_digit(i, num);
		if (num_digits){
			for (num_digits; num_digits>0; num_digits-=1){
				res = res*10 + i;
			}
		}
	}
	return res;
}


void process_arr(int **arr, int *len){
	int *new_arr = (int*)calloc(1, sizeof(int));
	if (!new_arr){
		printf("Failed to allocate memory\n");
	}
	int new_arr_len = 1;
	for (int i = 0; i < *len; i++){
		int is_bad = 0;
		for (int j = i + 1; j < *len; j++){
			if (get_digits(*(*arr+i)) == get_digits(*(*arr+j))){
				is_bad = 1;
				new_arr_len+=1;
				new_arr = (int*)realloc(new_arr, new_arr_len*sizeof(int));
				new_arr[new_arr_len-1] = *(*arr+j);
				for (int index = j; index < *len - 1; index++){
					*(*arr + index) = *(*arr + index+1);
				}
				*len-=1;
			}
		}
		if (is_bad){
			new_arr_len+=1;
			new_arr = (int*)realloc(new_arr, new_arr_len*sizeof(int));
			new_arr[new_arr_len-1] = *(*arr + i);
			for (int index = i; index < *len - 1; index++){
				*(*arr + index) = *(*arr + index+1);
			}
			*len-=1;
		}
	}
	if (new_arr_len == 1){
		free(new_arr);
		printf("There are no numbers with similar digits\n");
	}
	else{
		printf("New array is: ");
		for (int i = 1; i<new_arr_len; i++){
			printf("%d, ", new_arr[i]);
		}
		printf("\n");
		printf("Processed given array: ");
		for (int i = 0; i<*len; i++){
			printf("%d, ", *(*arr+i));
		}
		printf("\n");
		free(new_arr);
	}
}