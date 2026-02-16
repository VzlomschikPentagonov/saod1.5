#ifndef FUNC2_H
#define FUNC2_H

#include "allfunc.h"

/*сортировка методом прямого включения*/
Stats insert_sort(int32_t*, int32_t);
/*сортировка Шелла*/
Stats shell_sort(int32_t*, int32_t);
/*пирамидальная сортировка*/
void build_max_heap(int32_t*, int32_t, int32_t, Stats*);
Stats heap_sort(int32_t*, int32_t);
/*быстрая сортировка Хоара*/
void quick_sort_(int32_t*, int32_t, int32_t, Stats*);
Stats quick_sort(int32_t*, int32_t, int32_t);

#endif
