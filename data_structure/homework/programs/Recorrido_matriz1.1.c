#include <stdio.h>

#define a 10

void leeMatriz(int n, int m, int matriz[a][a]){
	printf("\nDime los elementos de la matriz: ");
	for (int j=m-1; j>=0; j--){
		for (int i=n-1; i>=0; i--){
			printf("\n[%d][%d]: ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
}

void imprimeMatriz(int n, int m, int matriz[a][a]){
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			printf("%4d", matriz[i][j]);
		}
		printf("\n");
	}
}

int main (){
	int n, m;
	int matriz[a][a];
	
	printf("\nDime el tamaño de la fila de la matriz nxm (osea n): ");
	scanf("%d", &n);
	printf("\nDime el tamaño de la columna de la matriz nxm (osea m): ");
	scanf("%d", &m);
	
	leeMatriz(n, m, matriz);
	imprimeMatriz(n, m, matriz);
	
	return 0;
	
}
