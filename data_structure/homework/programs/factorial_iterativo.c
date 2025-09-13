#include <stdio.h>
#include <stdlib.h>

int factItera(int n, int a){
	
	if (n < 0){
		return 0;
	}
	else if ( n == 0){
		return 1;
	}
	else if (n == 1){
		return a;
	}
	else if (n > 1){
		return factItera(n-1, n*a);
	}
}

int main(){
	int n, a;
	a=1;
	printf ("\nDame el numero: ");
	scanf("%d", &n);
	printf("\n El factorial es: %d", factItera(n,a));
	return 0;
}
