#include "../af/allfunc.h"
#include "func1.h"

/*сортировка методом прямого выбора*/
Stats select_sort(int32_t* array, int32_t length){
	int32_t i, j, index, index_new, temp;
	Stats stats;
        stats.swaps = 0, stats.comp = 0;
	const int32_t length_func = length - 1;
	for(i = 0; i < length_func; i++){
		index = i;
		index_new = index;
		for(j = i + 1; j <= length_func; j++){
			if(array[j] < array[index_new]){
				index_new = j;
			}
			stats.comp++;
		}
		temp = array[index_new];
		array[index_new] = array[index];
		array[index] = temp;
		stats.swaps += 3;
	}
	return stats;
}

/*сортировка методом пузырька*/
Stats bubble_sort(int32_t* array, int32_t length){
	int32_t i, j, temp;
	Stats stats;
	stats.swaps = 0, stats.comp = 0;
	const int32_t length_func = length - 1;
	for(i = 0; i < length_func; i++){
		for(j = length_func - 1; j >= i; j--){
			if(array[j] > array[j + 1]){
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				stats.swaps += 3;
			}
			stats.comp++;
		}
	}
	return stats;
}

/*шейкерная сортировка*/
Stats shaker_sort(int32_t* array, int32_t length){
	const int32_t length_func = length - 1;
	int32_t j, left_b = 0, right_b = length_func, set_b = length_func, temp;
        Stats stats;
        stats.swaps = 0, stats.comp = 0;
	do{
		for(j = right_b; j >= left_b + 1; j--){
			if(array[j] < array[j - 1]){
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
		                stats.swaps += 3;
				set_b = j;
			}
			stats.comp++;
		}
		left_b = set_b;
		for(j = left_b; j <= right_b - 1; j++){
			if(array[j] > array[j + 1]){
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
		                stats.swaps += 3;
				set_b = j;
			}
			stats.comp++;
		}
		right_b = set_b;
	}while(left_b < right_b);
        return stats;
}
