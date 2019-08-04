#include<stdio.h>
#include<conio.h>

int main() {
	int i, j, k, l, m, row;
	printf("Enter  number of rows that you want to display : ");
	scanf("%d", &row);
	
	for(int i=1; i<=row; i++) {
		for(j=(row); j>=i; j--) {
			printf("*");
		}
		
		for(k=1; k<i; k++) {
			printf(" ");
		}
		
		for(m=1; m<i; m++) {
			printf(" ");
		}
		
		for(l=(row); l>=i; l--) {
			printf("*");
		}
	
		printf("`\n");
	}
	return 0;
}
