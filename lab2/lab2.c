#include "func2.h"
#define LENGTH 500

int main(){
	srand(time(NULL));
	int32_t array[LENGTH];
	StFull all_stats[20];
	const char* sorts[20] = 
{"Insert sort (100)", "Insert sort (200)", "Insert sort (300)", "Insert sort (400)", "Insert sort (500)", 
"Shell sort (100)", "Shell sort (200)", "Shell sort (300)", "Shell sort (400)", "Shell sort (500)", 
"Heap sort (100)", "Heap sort (200)", "Heap sort (300)", "Heap sort (400)", "Heap sort (500)",
"Quick sort (100)", "Quick sort (200)", "Quick sort (300)", "Quick sort (400)", "Quick sort (500)"};
	uint16_t trials[6] = {5, 100, 200, 300, 400, 500};
	uint8_t p = 0;
	get_stats(insert_sort, array, all_stats, &p, trials);
        get_stats(shell_sort, array, all_stats, &p, trials);
        get_stats(heap_sort, array, all_stats, &p, trials);
	get_stats_(quick_sort, array, all_stats, &p, trials);
	print_table(all_stats, 20, sorts);
	return 0;
}
