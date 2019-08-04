#include<stdio.h>
#include<conio.h>

int main() {
	int i, j, k, row;
	printf("Enter number of rows you want to display : " );
	scanf("%d",&row);
	
	for(i=1; i<=row; i++) {
		for(k=1; k<i; k++) {
			printf(" ");
		}
		
		for(j=row; j>=i; j--) {
			printf("*");	
		}
		
		printf("\n");
	}
	
	return 0;
}
