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

typedef struct StFull{
	Stats asc;
	Stats desc;
	Stats rand;
}StFull;

typedef struct Node{
	struct Node* next;
	uint32_t data;
}Node;

typedef struct Stack{
        Node* head;
}Stack;

typedef struct Queue{
        Node* head;
	Node* tail;
}Queue;

/*функция заполнения массива псевдослучайными числами*/
void print_array(int32_t*, int32_t);
/*функция вывода массива*/
void fill_array_rand(int32_t*, int32_t);
/*сортировка массива*/
Stats sort(Stats(*)(int32_t*, int32_t), int32_t*, int32_t);
void get_stats(Stats(*)(int32_t*, int32_t), int32_t*,
	       StFull*, uint8_t*, uint16_t*);
Stats sort_(Stats(*)(int32_t*, int32_t, int32_t), int32_t*, int32_t, int32_t);
void print_table(StFull*, int32_t, const char**);
void get_stats_(Stats(*)(int32_t*, int32_t, int32_t), int32_t*,
               StFull*, uint8_t*, uint16_t*);

#endif
