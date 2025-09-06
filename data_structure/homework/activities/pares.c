#include <stdio.h>

int main (){
	int vect[10];
	
	for (int i=0; i<10; i++){
		vect[i]= 20-2*i;	
	}
	
	int numerocuenta, ultimo;
	
	printf("\nDame tu numero de cuenta: ");
	scanf("%d", &numerocuenta);
	
	ultimo = numerocuenta % 10;
	
	vect[ultimo]= -1;
	for (int i = 0; i<10;i++){
	printf ("\n%d", vect[i]);
	}
	
	return 0;

}
