#ifndef ARR
# define ARR


int *array_input(int *len, int *mem_al, int N);
void input_element(int index, int value, int **arr, int *len, int *mem_al, int N);
void remove_element(int index, int **arr, int *len, int *mem_al, int N);
int *process_arr(int **arr, int *len, int *new_len, int *old_mem_al, int *mem_al, int N);


#endif