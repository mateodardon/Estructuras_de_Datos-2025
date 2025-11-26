#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void heap(int vect[], int n, int i){
	int root=i;
	int left_child = 2*i+1 ;
	int right_child = 2*i+2;
	
	if (left_child<n && vect[left_child]>vect[root]){
		root=left_child;
	}
	
	if (right_child<n && vect[right_child]>vect[root]){
		root=right_child;
	}
	
	if(root!=i){
		int temp=vect[i];
		vect[i]=vect[root];
		vect[root]=temp;
		
		heap(vect, n, root);
	}
}

void heapSort(int vect[], int n){
	for (int i=n/2-1; i>=0; i--){
		heap(vect, n, i);
	}
	for (int i=n-1; i>0; i--){
		int temp=vect[0];
		vect[0]=vect[i];
		vect[i]=temp;
		
		heap(vect, i, 0);
	}
}

int main(int argc, char *argv[]){
	int n=argc-1;
	int vect[n];
	
	for (int i=0; i<n; i++){
		vect[i] = atoi(argv[i+1]);
	}
	
	heapSort(vect, n);
	
	printf("Arreglo ordenado: ");
	for (int i=0; i<n; i++){
		printf(" %d ", vect[i]);
	}
	
	return 0;
}
