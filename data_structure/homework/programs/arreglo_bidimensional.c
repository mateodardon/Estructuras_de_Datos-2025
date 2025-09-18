#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	int n;
	int edades=0;
	int calificaciones=0;
	float promedioEdades=0;
	float promedioCalificaciones=0;
	
	printf("\nDime el numero de alumnos: ");
	scanf("%d", &n);
	char **matriz= (char **)malloc((n+1) * 3 * sizeof(char *));
	for (int i=0; i<(n+1)*3; i++){
		matriz[i]=(char *)malloc(25 * sizeof(char));
	}
	
	strcpy(matriz[0], "Nombre");
	strcpy(matriz[1], "Edad");
	strcpy(matriz[2], "Calificacion");
	
	for(int i=n; i>=1; i--){
		for (int j=0; j<3; j++){
			if (j==0){
				printf("\nDime el nombre: ");
			}
			else if(j==1){
				printf("\nDime la edad: ");
			}
			else if(j==2){
				printf("\nDame la calificacion: ");
			}
			scanf(" %[^\n]", matriz[i*3+j]);
		}
	}
	
	for(int i=0; i<=n; i++){
		for (int j=0; j<3; j++){
			printf("| %s |", matriz[i*3+j]);
		}
		printf("\n");
	}
	
	for(int i=1; i<=n; i++){
		edades += atoi(matriz[i*3+1]);
		calificaciones += atoi(matriz[i*3+2]);
	}
	
	promedioEdades= (float) edades/n;
	promedioCalificaciones= (float) calificaciones/n;
	
	printf("\nPromedio de edad: %f", promedioEdades);
	printf("\nPromedio de calificaciones: %f", promedioCalificaciones);
	
	for (int i=0; i<n*3; i++){
		free(matriz[i]);
	}
	free(matriz);
	
	return 0;
}
