/*
    stack.c
*/
#include <stdlib.h>
#include "stack.h"
#include "list.h"

/* Empujar elemento a la pila (Push) -> Insertar al inicio de la lista */
int stack_push(Stack *stack, const void *data) {
    return list_ins_next(stack, NULL, data);
}

/* Sacar elemento de la pila (Pop) -> Remover del inicio de la lista */
int stack_pop(Stack *stack, void **data) {
    return list_rem_next(stack, NULL, data);
}