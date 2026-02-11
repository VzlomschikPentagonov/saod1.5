#include "func1.h"
#define LENGTH 500

int main(){
	srand(time(NULL));
	int32_t array[LENGTH];
	Stats stats;
	for(int32_t i = 10; i < 150; i += 90){
		fill_array_rand(array, i);
		stats = sort(select_sort, array, i);
		printf("Swaps: %d\nComp: %d\n\n", stats.swaps, stats.comp);
	}
	for(int32_t i = 100; i < 600; i += 100){
                fill_array_rand(array, i);
                stats = sort(bubble_sort, array, i);
                printf("Swaps: %d\nComp: %d\n\n", stats.swaps, stats.comp);
        }
	for(int32_t i = 100; i < 600; i += 100){
                fill_array_rand(array, i);
                stats = sort(shaker_sort, array, i);
                printf("Swaps: %d\nComp: %d\n\n", stats.swaps, stats.comp);
        }
	return 0;
}
