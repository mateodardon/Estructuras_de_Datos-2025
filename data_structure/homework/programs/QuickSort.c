#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int dividir(int vect[], int l, int h){
	int pivote= vect[h];
	int i=l-1;
	int temp;
	
	for(int j=l; j<h; j++){
		if(vect[j]<= pivote){
			i=i+1;
			temp = vect[i];
			vect[i] = vect[j];
			vect[j] = temp;
		}
	}
	temp = vect[i+1];
	vect[i+1] = vect[h];
	vect[h] = temp; 
	
	return i+1;
}

void quickSort(int vect[], int l, int h){
	if (l<h){
		int d = dividir(vect, l, h);
		
		quickSort(vect, l, d-1);
		quickSort(vect, d+1, h);
	}
}


int main(int argc, char *argv[]){
	int n = argc -1;	
	int vect[n];
	
	for (int i=0; i<n; i++){
		vect[i] = atoi(argv[i+1]);
	}
	
	printf("Arreglo: ");
	for (int i=0; i<n;i++){
		printf(" %d ", vect[i]);
	}
	
	quickSort(vect, 0, n-1);
	
	printf("\nArreglo ordenado: ");
	for (int i=0; i<n;i++){
		printf(" %d ", vect[i]);
	}
	
	return 0;
}

