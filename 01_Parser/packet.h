#ifndef PACKET_H
#define PACKET_H
#include "field.h"

typedef struct packet {
    char id[15]; 
    char firstName[15];
    char lastName[15];
    struct packet *next;
}packet_t;

typedef struct{
    packet_t *top;
}stack_t;

stack_t *createStack();
void push(packet_t *pack,stack_t *stack);
packet_t *pop(stack_t *stack);
void freeStack(stack_t *stack);
void PrintStack(stack_t *stack,fields_t *fields);
#endif
