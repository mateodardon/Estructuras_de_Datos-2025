#include <stdio.h>

#define a 10

void diagonal(int n, int m, int matriz[a][a]){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			matriz[i][j]=0;
		}
	}
}

void leeMatriz1(int n, int matriz[a][a]){
	printf("\nDime los elementos de la matriz: ");
	for (int i=0; i<n ; i++){
		printf("\n[%d][%d]: ", i, i);
		scanf("%d", &matriz[i][i]);
	}
}
void leeMatriz2(int m, int matriz[a][a]){
	printf("\nDime los elementos de la matriz: ");
	for (int i=0; i<m ; i++){
		printf("\n[%d][%d]: ", i, i);
		scanf("%d", &matriz[i][i]);
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
	
	diagonal(n, m, matriz);
	
	if (n<m){
		leeMatriz1(n, matriz);
	}
	else {
		leeMatriz2(m, matriz);
	}
	imprimeMatriz(n, m, matriz);
	
	return 0;
	
}
