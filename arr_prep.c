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


int *process_arr(int **arr, int *len, int *new_arr_len){
	int N = 5;
	int *new_arr = (int*)calloc(N, sizeof(int));
	if (!new_arr){
		printf("Failed to allocate memory\n");
	}
	int mem_al = N;
	for (int i = 0; i < *len; i++){
		int is_bad = 0;
		for (int j = i + 1; j < *len; j++){
			if (get_digits(*(*arr+i)) == get_digits(*(*arr+j))){
				is_bad = 1;
				*new_arr_len+=1;
				if (*new_arr_len > mem_al){
					mem_al+=N;
					new_arr = (int*)realloc(new_arr, mem_al*sizeof(int));
				}
				new_arr[*new_arr_len-1] = *(*arr+j);
				remove_element(j, arr, len);
				j-=1;
			}
		}
		if (is_bad){
			*new_arr_len+=1;
			if (*new_arr_len > mem_al){
				mem_al+=N;
				new_arr = (int*)realloc(new_arr, mem_al*sizeof(int));
			}
			new_arr[*new_arr_len-1] = *(*arr + i);
			remove_element(i, arr, len);
			i-=1;
		}
	}
	new_arr = (int*)realloc(new_arr, *new_arr_len*sizeof(int));
	printf("New array is: ");
	for (int i = 0; i<*new_arr_len; i++){
		printf("%d, ", new_arr[i]);
	}
	printf("\n");
	printf("Processed given array: ");
	for (int i = 0; i<*len; i++){
		printf("%d, ", *(*arr+i));
	}
	printf("\n");
	return new_arr;
}