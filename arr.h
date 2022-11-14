#ifndef ARR
# define ARR


int *array_input(int *len);
void input_element(int index, int value, int **arr, int *len);
void remove_element(int index, int **arr, int *len);
int *process_arr(int **arr, int *len, int *new_len);


#endif