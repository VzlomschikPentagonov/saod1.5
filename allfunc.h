#ifndef ALLFUNC_H
#define ALLFUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

typedef struct Stats{
	uint32_t swaps;
        uint32_t comp;
}Stats;

/*функция заполнения массива псевдослучайными числами*/
void print_array(int32_t*, int32_t);
/*функция вывода массива*/
void fill_array_rand(int32_t*, int32_t);
/*сортировка массива*/
Stats sort(Stats(*)(int32_t*, int32_t), int32_t*, int32_t);
Stats sort_(Stats(*)(int32_t*, int32_t, int32_t), int32_t*, int32_t, int32_t);

#endif
