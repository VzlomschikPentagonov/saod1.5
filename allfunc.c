#include "allfunc.h"

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
