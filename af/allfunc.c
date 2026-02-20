#include "allfunc.h"

void fill_array_asc(int32_t* array, int32_t length){
        int32_t i;
        for(i = 0; i < length; i++){
                array[i] = i;
        }
}

void fill_array_desc(int32_t* array, int32_t length){
        int32_t i;
        for(i = 0; i < length; i++){
                array[i] = length - 1 - i;
        }
}

/*функция заполнения массива псевдослучайными числами*/
void fill_array_rand(int32_t* array, int32_t length){
	int32_t i;
	for(i = 0; i < length; i++){
		array[i] = rand() % length;
	}
}

/*функция вывода массива*/
void print_array(int32_t* array, int32_t length){
	int32_t i = 0;
	printf("[");
	printf("%d, ", array[i]);
	for(i = 1; i < length - 1; i++){
		printf("%2d, ", array[i]);
	}
	printf("%2d]\n\n", array[length - 1]);
}

/*сортировка массива*/
Stats sort(Stats(*func)(int32_t*, int32_t), int32_t* array, int32_t length){
	return func(array, length);
}

void get_stats(Stats(*func)(int32_t*, int32_t), int32_t* array,
               StFull* st_a, uint8_t *p, uint16_t* trials){
	for(int j = 1; j < (*trials) + 1; j++){
                fill_array_asc(array, trials[j]);
                st_a[*p].asc = sort(func, array, trials[j]);
                fill_array_desc(array, trials[j]);
                st_a[*p].desc = sort(func, array, trials[j]);
		fill_array_rand(array, trials[j]);
		st_a[*p].rand = sort(func, array, trials[j]);
		p[0]++;
	}
}

/*сортировка массива*/
Stats sort_(Stats(*func)(int32_t*, int32_t, int32_t), int32_t* array, int32_t length, int32_t var){
        return func(array, length, var);
}

void get_stats_(Stats(*func)(int32_t*, int32_t, int32_t), int32_t* array,
               StFull* st_a, uint8_t *p, uint16_t* trials){
        for(int j = 1; j < (*trials) + 1; j++){
                fill_array_asc(array, trials[j]);
                st_a[*p].asc = sort_(func, array, 0, trials[j] - 1);
                fill_array_desc(array, trials[j]);
                st_a[*p].desc = sort_(func, array, 0, trials[j] - 1);
                fill_array_rand(array, trials[j]);
                st_a[*p].rand = sort_(func, array, 0, trials[j] - 1);
                p[0]++;
        }
}


void print_table(StFull* st_a, int32_t length, const char** sorts){
	printf("@-------------------@-----------@------------@--------@\n"
               "| Sort              | Ascending | Descending | Random |\n");
	for(int i = 0; i < length; i++){
		printf("@-------------------@-----------@------------@--------@\n"
		       "| %17s | %6d    | %6d     | %6d |\n",
		sorts[i], st_a[i].asc.comp, st_a[i].desc.comp, st_a[i].rand.comp);
		printf("@-------------------@-----------@------------@--------@\n"
                       "| %17s | %6d    | %6d     | %6d |\n",
                sorts[i], st_a[i].asc.swaps, st_a[i].desc.swaps, st_a[i].rand.swaps);
	}
	printf("@-------------------@-----------@------------@--------@\n");
}
