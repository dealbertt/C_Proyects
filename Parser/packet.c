#include <stdio.h>
#include <stdlib.h>
#include "packet.h"
#include "json.h"
#include "field.h"


stack_t *createStack(){
    stack_t *stack = malloc(sizeof(stack_t));
    if(stack) stack->top = NULL;
    return stack;
}
packet_t *pop(stack_t *stack){
    if(stack->top == NULL) return NULL;
    packet_t *packet = stack->top;
    stack->top = stack->top->next;
    packet->next = NULL;
    return packet;
}
void push(packet_t *pack,stack_t *stack){
    pack->next = stack->top;
    stack->top = pack;
}
void freeStack(stack_t *stack){
    while(stack->top != NULL){
        packet_t *packet = pop(stack);
        free(packet);
    }
    free(stack);
}
void PrintStack(stack_t *stack, fields_t *fields){
    while(stack->top != NULL){
        printf("%s: %s\n",fields->f1,stack->top->id);
        printf("%s: %s\n",fields->f2,stack->top->firstName);
        printf("%s: %s\n",fields->f3,stack->top->lastName);
        toJson(stack->top,fields);
        stack->top = stack->top->next;
    }
}
