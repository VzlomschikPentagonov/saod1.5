#include "../af/allfunc.h"
#include "func2.h"

/*сортировка методом прямого включения*/
Stats insert_sort(int32_t* array, int32_t length){
	const int32_t length_func = length - 1;
	int32_t i, j, temp;
	Stats stats;
	stats.swaps = 0, stats.comp = 0;
	for(i = 1; i <= length_func; i++){
		temp = array[i];
		j = i - 1;
		stats.comp += 2;
		while(j > -1 && temp < array[j]){
			array[j + 1] = array[j];
			j--;
			stats.swaps += 2;
		}
		array[j + 1] = temp;
	}
	return stats;
}

/*сортировка Шелла*/
Stats shell_sort(int32_t* array, int32_t length){
	int32_t i, j, temp, k_sort;
	Stats stats;
	stats.swaps = 0, stats.comp = 0;
	for(k_sort = length >> 1; k_sort > 0; k_sort >>= 1){
		for(i = k_sort; i < length; i++){
			temp = array[i];
			j = i;
			stats.comp += 2;
			while(j >= k_sort && temp < array[j - k_sort]){
				array[j] = array[j - k_sort];
				j -= k_sort;
				stats.swaps += 2;
			}
			array[j] = temp;
		}
	}
	return stats;
}

/*пирамидальная сортировка*/
void build_max_heap(int32_t* array, int32_t length, int32_t i, Stats *stats){
	int32_t root = i, max_node = i, left, right, temp;
	do{
		left = (root << 1) + 1;
		right = (root << 1) + 2;
		stats -> comp += 2;
		if(left < length && array[left] > array[max_node]){
			max_node = left;
		}
		stats -> comp += 2;
		if(right < length && array[right] > array[max_node]){
			max_node = right;
		}
		stats -> comp++;
		if(max_node != root){
			temp = array[root];
			array[root] = array[max_node];
			array[max_node] = temp;
		stats -> swaps += 3;
		}
		else{
			break;
		}
		stats -> comp++;
		root = max_node;
	}while(root < (length >> 1));
}

Stats heap_sort(int32_t* array, int32_t length){
	int32_t i, temp;
	Stats stats;
	stats.swaps = 0, stats.comp = 0;
	for(i = (length >> 1) - 1; i >= 0; i--){
		build_max_heap(array, length, i, &stats);
	}
	for(i = length - 1; i > 0; i--){
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		stats.swaps += 3;
		build_max_heap(array, i, 0, &stats);
	}
	return stats;
}

void quick_sort_(int32_t* array, int32_t left, int32_t right, Stats *stats){
        int32_t pivot = array[left], i = left, j = right, temp;
        stats -> comp++;
        while(i <= j){
                stats -> comp++;
                while(array[i] < pivot){
                        i++;
                        stats -> comp++;
                }
                while(array[j] > pivot){
                        j--;
                        stats -> comp++;
                }
                stats -> comp++;
                if(i <= j){
                        temp = array[i];
                        array[i] = array[j];
                        array[j] = temp;
                        stats -> swaps += 3;
                        i++;
                        j--;
                        stats -> comp++;
                }
        }
        stats -> comp++;
        if(left < j){
                quick_sort_(array, left, j, stats);
        }
        stats -> comp++;
        if(i < right){
                quick_sort_(array, i, right, stats);
        }
}

/*быстрая сортировка Хоара*/
Stats quick_sort(int32_t* array, int32_t left, int32_t right){
	int32_t pivot = array[left], i = left, j = right, temp;
	static Stats stats;
	stats.swaps = 0, stats.comp = 0;
	stats.comp++;
	while(i <= j){
		stats.comp++;
		while(array[i] < pivot){
			i++;
			stats.comp++;
		}
		while(array[j] > pivot){
			j--;
			stats.comp++;
		}
		stats.comp++;
		if(i <= j){
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			stats.swaps += 3;
			i++;
			j--;
			stats.comp++;
		}
	}
	stats.comp++;
	if(left < j){
		quick_sort_(array, left, j, &stats);
	}
	stats.comp++;
	if(i < right){
		quick_sort_(array, i, right, &stats);
	}
	return stats;
}
