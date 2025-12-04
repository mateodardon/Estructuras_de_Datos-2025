/*
    converter.h
*/
#ifndef CONVERTER_H
#define CONVERTER_H

/* Convierte notación infija a postfija. 'detallado' imprime pasos. */
int infix_to_postfix(const char *infija, char *postfija, int detallado);

/* Convierte notación infija a prefija. */
void infix_to_prefix(const char *infija, char *prefija);

/* Evalúa expresión postfija (solo numérica). Retorna 0 si éxitoso. */
int evaluate_postfix(char *postfija, double *resultado);

/* Verifica si la expresión es numérica o algebraica */
int is_numeric_expression(const char *expr);

int postfix_to_prefix(const char *postfija, char *prefija);
int prefix_to_postfix(const char *prefija, char *postfija);

#endif