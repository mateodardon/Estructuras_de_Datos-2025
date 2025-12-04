/*
    calc.c
*/
/*
    Equipo: 
    Reyes Dardón Mateo Imanol
    Romo Martinez Emiliano
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "converter.h"

#define MAX_EXPR 256

void mostrar_ayuda() {
    printf("\nUso: ./calc [FLAG] \"expresion\"\n\n");
    printf("Banderas disponibles:\n");
    printf("  -i    : La entrada es INFIJA (ej: \"a+b\")\n");
    printf("  -p    : La entrada es POSTFIJA (ej: \"ab+\")\n");
    printf("  -pre  : La entrada es PREFIJA (ej: \"+ab\")\n");
    printf("  -h    : Muestra esta ayuda\n\n");
    printf("Ejemplos:\n");
    printf("  ./calc -i \"(3+2)*4\"\n");
    printf("  ./calc -p \"32+4*\"\n");
}

void guardar_log(const char *tipo, const char *entrada, const char *res_str, double res_num, int es_num) {
    FILE *f = fopen("historial.txt", "a");
    if (!f) return;
    fprintf(f, "[%s] In: %s | ", tipo, entrada);
    if (es_num) fprintf(f, "Res: %.2f\n", res_num);
    else fprintf(f, "Res: %s (Alg)\n", res_str);
    fclose(f);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        mostrar_ayuda();
        return 1;
    }

    if (strcmp(argv[1], "-h") == 0) {
        mostrar_ayuda();
        return 0;
    }

    if (argc < 3) {
        printf("Error: Falta la expresion.\n");
        printf("Uso correcto: ./calc -i \"(a+b)\"\n");
        return 1;
    }

    char *flag = argv[1];
    char *entrada = argv[2];
    
    char postfija[MAX_EXPR] = {0};
    char prefija[MAX_EXPR] = {0};
    char infija_reconst[MAX_EXPR] = {0};
    
    double resultado = 0.0;
    int error = 0;
    char tipo_detectado[10] = {0};

    printf("Procesando: %s\n", entrada);

    
    if (strcmp(flag, "-i") == 0) {
        /* ENTRADA INFIJA */
        strcpy(tipo_detectado, "INFIJA");
        strcpy(infija_reconst, entrada);
        
        if (infix_to_postfix(entrada, postfija, 1) != 0) error = 1;
        else infix_to_prefix(entrada, prefija);

    } else if (strcmp(flag, "-p") == 0) {
        /* ENTRADA POSTFIJA */
        strcpy(tipo_detectado, "POSTFIJA");
        strcpy(postfija, entrada);
        
        if (postfix_to_prefix(entrada, prefija) != 0) error = 1;

    } else if (strcmp(flag, "-pre") == 0) {
        /* ENTRADA PREFIJA */
        strcpy(tipo_detectado, "PREFIJA");
        strcpy(prefija, entrada);
        
        if (prefix_to_postfix(entrada, postfija) != 0) error = 1;

    } else {
        printf("Error: Bandera '%s' no reconocida.\n", flag);
        mostrar_ayuda();
        return 1;
    }

    if (error) {
        printf("Error al procesar la expresion.\n");
        return 1;
    }

    printf("\n--- Resultados ---\n");
    printf("Tipo Original: %s\n", tipo_detectado);
    if(postfija[0]) printf("Postfija:      %s\n", postfija);
    if(prefija[0])  printf("Prefija:       %s\n", prefija);

    int es_num = is_numeric_expression(postfija);
    if (es_num) {
        if (evaluate_postfix(postfija, &resultado) == 0)
            printf("Evaluacion:    %.2f\n", resultado);
        else
            printf("Evaluacion:    Error matematico (div/0 o mal formato)\n");
    } else {
        printf("Evaluacion:    N/A (Es algebraica)\n");
    }

    guardar_log(tipo_detectado, entrada, postfija, resultado, es_num);
    printf("\n[Archivo] Guardado en historial.txt\n");

    return 0;
}