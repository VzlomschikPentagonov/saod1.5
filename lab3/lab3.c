#include "func3.h"
#define LENGTH 50

int main(){
	srand(time(NULL));
	Stack s;
	s.head = get_stack();
	fill(rand_, &s, LENGTH);
	print_stack(&s);
	delete_node(&s);
	print_stack(&s);
	Queue q;
//	q.head = NULL;
//	q.tail = NULL;
//	addq_empty(&q, 123);
//	fillq(randq, &q, LENGTH);
//	print_queue(&q);
	return 0;
}
