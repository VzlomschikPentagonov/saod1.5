#include "func1.h"
#define LENGTH 500

int main(){
	srand(time(NULL));
	int32_t array[LENGTH];
	StFull all_stats[12];
	const char* sorts[12] = {"Select sort (10)", "Select sort (100)",
"Bubble sort (100)", "Bubble sort (200)", "Bubble sort (300)", "Bubble sort (400)", "Bubble sort (500)", 
"Shaker sort (100)", "Shaker sort (200)", "Shaker sort (300)", "Shaker sort (400)", "Shaker sort (500)"};
	uint16_t ss_trials[3] = {2, 10, 100};
	uint16_t trials[6] = {5, 100, 200, 300, 400, 500};
	uint8_t p = 0;
	get_stats(select_sort, array, all_stats, &p, ss_trials);
        get_stats(bubble_sort, array, all_stats, &p, trials);
        get_stats(shaker_sort, array, all_stats, &p, trials);
	/*for(int i = 0; i < p; i++){
		printf("%d, %d, %d\n", all_stats[i].asc.comp, all_stats[i].desc.comp,
		all_stats[i].rand.comp);
		printf("%d, %d, %d\n", all_stats[i].asc.swaps, all_stats[i].desc.swaps,
                all_stats[i].rand.swaps);
	}*/
	print_table(all_stats, 12, sorts);
	return 0;
}
