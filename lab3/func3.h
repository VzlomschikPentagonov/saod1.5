#ifndef FUNC3_H
#define FUNC3_H

#include "../af/allfunc.h"

Node* get_stack();
void add(Stack*, int32_t);
void print_stack(Stack*);
void delete_node(Stack*);
void asc(Stack*, int32_t);
void desc(Stack*, int32_t);
void rand_(Stack*, int32_t);
void fill(void(*)(Stack*, int32_t), Stack*, int32_t);
void get_queue(Queue*);
void addq_empty(Queue*, int32_t);
void addq(Queue*, int32_t);
void descq(Queue*, int32_t);
void ascq(Queue*, int32_t);
void randq(Queue*, int32_t);
void fillq(void(*)(Queue*, int32_t), Queue*, int32_t);
void print_queue(Queue*);

#endif
