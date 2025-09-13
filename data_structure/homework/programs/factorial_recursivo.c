#include <stdio.h>
#include <stdlib.h>

int factRecursion(int n){
	
	if (n < 0){
		return 0;
	}
	else if ( n == 0){
		return 1;
	}
	else if (n == 1){
		return 1;
	}
	else if (n > 1){
		return n *factRecursion(n-1);
	}
}

int main(){
	int n;
	printf ("\nDame el numero: ");
	scanf("%d", &n);
	printf("\n El factorial es: %d", factRecursion(n));
	return 0;
}
