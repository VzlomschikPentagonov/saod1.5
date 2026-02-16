#include "func2.h"
#define LENGTH 500

int main(){
	srand(time(NULL));
	int32_t array[LENGTH];
	Stats stats;
	puts("Insert Sort:\n");
	for(int32_t i = 100; i < 600; i += 100){
		fill_array_rand(array, i);
		stats = sort(insert_sort, array, i);
		printf("Swaps: %d\nComp: %d\n\n", stats.swaps, stats.comp);
	}
	puts("Shell Sort:\n");
	for(int32_t i = 100; i < 600; i += 100){
                fill_array_rand(array, i);
                stats = sort(shell_sort, array, i);
                printf("Swaps: %d\nComp: %d\n\n", stats.swaps, stats.comp);
        }
	puts("Heap Sort:\n");
	for(int32_t i = 100; i < 600; i += 100){
                fill_array_rand(array, i);
                stats = sort(heap_sort, array, i);
                printf("Swaps: %d\nComp: %d\n\n", stats.swaps, stats.comp);
        }
	puts("Quick Sort:\n");
	for(int32_t i = 100; i < 600; i += 100){
                fill_array_rand(array, i);
                stats = sort_(quick_sort, array, 0, i - 1);
                printf("Swaps: %d\nComp: %d\n\n", stats.swaps, stats.comp);
        }
	return 0;
}
