#ifndef FUNC1_H
#define FUNC1_H

#include "../af/allfunc.h"

/*сортировка методом прямого выбора*/
Stats select_sort(int32_t*, int32_t);
/*сортировка методом пузырька*/
Stats bubble_sort(int32_t*, int32_t);
/*шейкерная сортировка*/
Stats shaker_sort(int32_t*, int32_t);
#endif
