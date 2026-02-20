#include "../af/allfunc.h"
#include "func3.h"

Node* get_stack(){
	return NULL;
}

void add(Stack *s, int32_t value){
	Node *p = (Node*)malloc(sizeof(Node));
	p -> data = value;
	p -> next = s -> head;
	s -> head = p;
	free(p);
}

void print_stack(Stack *s){
	Node *p = s -> head;
	printf("[");
	while(p != NULL){
		if(p -> next == NULL) printf("%d", p -> data);
		else printf("%d, ", p -> data);
		p = p -> next;
	}
	puts("]\n");
}

void delete_node(Stack *s){
        Node *p = s -> head;
	s -> head = p -> next;
}

void desc(Stack *s, int32_t length){
	for(int i = 0; i < length; i++) add(s, i);
}

void asc(Stack *s, int32_t length){
        for(int i = 0; i < length; i++) add(s, length - i - 1);
}

void rand_(Stack *s, int32_t length){
        for(int i = 0; i < length; i++) add(s, rand() % length);
}

void fill(void(*func)(Stack*, int32_t), Stack *s, int32_t length){
	func(s, length);
}

void get_queue(Queue *q){
	q -> head = NULL;
	q -> tail = NULL;
}

void addq_empty(Queue *q, int32_t value){
        Node *p = (Node*)malloc(sizeof(Node));
        p -> data = value;
        p -> next = NULL;
        q -> head = p;
        q -> tail = p;
	free(p);
}

void addq(Queue *q, int32_t value){
        Node *p = (Node*)malloc(sizeof(Node));
        p -> data = value;
        p -> next = NULL;
        q -> tail -> next = p;
	q -> tail = p;
        free(p);
}

void descq(Queue *q, int32_t length){
        for(int i = 0; i < length; i++) addq(q, i);
}

void ascq(Queue *q, int32_t length){
        for(int i = 0; i < length; i++) addq(q, length - i - 1);
}

void randq(Queue *q, int32_t length){
        for(int i = 0; i < length; i++) addq(q, rand() % length);
}


void fillq(void(*func)(Queue*, int32_t), Queue *q, int32_t length){
        func(q, length);
}

void print_queue(Queue *q){
        Node *p = q -> head;
        printf("[");
        while(p != NULL){
                if(p -> next == NULL) printf("%d", p -> data);
                else printf("%d, ", p -> data);
                p = p -> next;
        }
	puts("]\n");
}
