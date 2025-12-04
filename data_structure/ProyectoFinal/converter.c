/*
    converter.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "stack.h"
#include "converter.h"

static int es_operador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

static int precedencia(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

static void invertir_cadena(char *cadena) {
    int n = strlen(cadena);
    for (int i = 0; i < n / 2; i++) {
        char temporal = cadena[i];
        cadena[i] = cadena[n - i - 1];
        cadena[n - i - 1] = temporal;
    }
}

/* --- Detección de Tipo --- */
int detect_notation_type(const char *expr) {
    int len = strlen(expr);
    if (len == 0) return 0;

    if (strchr(expr, '(') || strchr(expr, ')')) return 0;

    char first = expr[0];
    char last = expr[len - 1];

    if (es_operador(last)) return 1; 
    if (es_operador(first)) return 2; 

    return 0; 
}

int infix_to_postfix(const char *infija, char *postfija, int detallado) {
    Stack pila;
    stack_init(&pila, free);
    int i = 0, k = 0;
    
    if(detallado) printf("\n--- Paso a Paso (Infija -> Postfija) ---\n");

    while (infija[i] != '\0') {
        char c = infija[i];
        if (isalnum(c)) {
            postfija[k++] = c;
            if(detallado) printf("Leido: %c | Salida: %s\n", c, postfija);
        } else if (c == '(') {
            char *d = malloc(sizeof(char)); *d = c; stack_push(&pila, d);
        } else if (c == ')') {
            char *popped;
            while (stack_size(&pila) > 0 && *(char*)stack_peek(&pila) != '(') {
                stack_pop(&pila, (void**)&popped); postfija[k++] = *popped; free(popped);
            }
            if (stack_size(&pila) > 0) { stack_pop(&pila, (void**)&popped); free(popped); }
        } else if (es_operador(c)) {
            while (stack_size(&pila) > 0 && *(char*)stack_peek(&pila) != '(' &&
                   precedencia(*(char*)stack_peek(&pila)) >= precedencia(c)) {
                char *popped; stack_pop(&pila, (void**)&popped); postfija[k++] = *popped; free(popped);
            }
            char *d = malloc(sizeof(char)); *d = c; stack_push(&pila, d);
            if(detallado) printf("Leido: %c | Stack Update\n", c);
        }
        i++;
    }
    while (stack_size(&pila) > 0) {
        char *popped; stack_pop(&pila, (void**)&popped); postfija[k++] = *popped; free(popped);
    }
    postfija[k] = '\0';
    stack_destroy(&pila);
    return 0;
}

void infix_to_prefix(const char *infija, char *prefija) {
    char temp[256]; strcpy(temp, infija);
    invertir_cadena(temp);
    for (int i = 0; i < strlen(temp); i++) {
        if (temp[i] == '(') temp[i] = ')';
        else if (temp[i] == ')') temp[i] = '(';
    }
    char post_temp[256] = {0};
    infix_to_postfix(temp, post_temp, 0);
    invertir_cadena(post_temp);
    strcpy(prefija, post_temp);
}


int postfix_to_prefix(const char *postfija, char *prefija) {
    Stack s;
    stack_init(&s, free);
    int i = 0;

    while (postfija[i] != '\0') {
        char c = postfija[i];
        if (isalnum(c)) {
            char *op = malloc(2 * sizeof(char));
            op[0] = c; op[1] = '\0';
            stack_push(&s, op);
        } else if (es_operador(c)) {
            char *op1, *op2;
            if (stack_pop(&s, (void**)&op2) != 0 || stack_pop(&s, (void**)&op1) != 0) {
                stack_destroy(&s); return -1;
            }
            int len = strlen(op1) + strlen(op2) + 2;
            char *nuevo = malloc(len * sizeof(char));
            sprintf(nuevo, "%c%s%s", c, op1, op2);
            
            free(op1); free(op2);
            stack_push(&s, nuevo);
        }
        i++;
    }
    
    char *res;
    if (stack_pop(&s, (void**)&res) == 0) {
        strcpy(prefija, res);
        free(res);
        stack_destroy(&s);
        return 0;
    }
    return -1;
}

int prefix_to_postfix(const char *prefija, char *postfija) {
    Stack s;
    stack_init(&s, free);
    int len = strlen(prefija);
    
    for (int i = len - 1; i >= 0; i--) {
        char c = prefija[i];
        if (isalnum(c)) {
            char *op = malloc(2 * sizeof(char));
            op[0] = c; op[1] = '\0';
            stack_push(&s, op);
        } else if (es_operador(c)) {
            char *op1, *op2;
            if (stack_pop(&s, (void**)&op1) != 0 || stack_pop(&s, (void**)&op2) != 0) {
                stack_destroy(&s); return -1;
            }
            int l = strlen(op1) + strlen(op2) + 2;
            char *nuevo = malloc(l * sizeof(char));
            sprintf(nuevo, "%s%s%c", op1, op2, c);
            
            free(op1); free(op2);
            stack_push(&s, nuevo);
        }
    }
    
    char *res;
    if (stack_pop(&s, (void**)&res) == 0) {
        strcpy(postfija, res);
        free(res);
        stack_destroy(&s);
        return 0;
    }
    return -1;
}

int evaluate_postfix(char *postfija, double *resultado) {
    Stack pila;
    stack_init(&pila, free);
    int i = 0, error = 0;

    while (postfija[i] != '\0') {
        if (isdigit(postfija[i])) {
            double *val = malloc(sizeof(double)); *val = postfija[i] - '0'; stack_push(&pila, val);
        } else if (es_operador(postfija[i])) {
            double *v2, *v1;
            if (stack_pop(&pila, (void**)&v2) != 0 || stack_pop(&pila, (void**)&v1) != 0) { error=1; break; }
            double res = 0;
            switch(postfija[i]) {
                case '+': res = *v1 + *v2; break;
                case '-': res = *v1 - *v2; break;
                case '*': res = *v1 * *v2; break;
                case '/': if(*v2==0) error=1; else res = *v1 / *v2; break;
                case '^': res = pow(*v1, *v2); break;
            }
            free(v1); free(v2);
            double *r = malloc(sizeof(double)); *r = res; stack_push(&pila, r);
        }
        i++;
    }
    if (!error && stack_size(&pila)==1) {
        double *f; stack_pop(&pila, (void**)&f); *resultado = *f; free(f);
    } else error=1;
    stack_destroy(&pila);
    return error;
}

int is_numeric_expression(const char *expr) {
    for(int j=0; j<strlen(expr); j++) if (isalpha(expr[j])) return 0;
    return 1;
}