#include <stdio.h>
#include <stdlib.h>

int fact(int a){
	if (a <= 0){
		return 1;
	}
	else if (a == 1){
		return 1;
	}
	else if (a > 1){
		return a *fact(a-1);
	}
}

int main (){
	int n;
	printf ("\nDame el numero: ");
	scanf("%d", &n);
	printf("\n El factorial es: %d", fact(n));
	return 0;
}
