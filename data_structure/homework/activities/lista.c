#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int n;
	printf("\nDime el numero de alumnos: ");
	scanf("%d", &n);
	
	char lista[n][3][25];
	
	for (int i=0; i<n; i++){
		for(int j=0; j<3; j++){
		if (j == 0){
			printf("\nDame el nombre: ");
			}	
			else if(j == 1){
				printf("\nDame la edad: ");
			}
			else if(j == 2){
				printf("\nDame la calificacion: ");
			}
			scanf("%s", lista[i][j]);
		}
	}
	
	printf("\nNombre\tEdad\tCalificacion\n");
	for (int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			printf("%s\t", lista[i][j]);
		}
		printf("\n");

	}
	
	for (int i=0; i<n; i++){
		int edad = atoi(lista[i][1]);
		int calif= atoi(lista[i][2]);
	}
	
	return 0;
}
