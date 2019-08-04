#include<stdio.h>
#include<conio.h>

int main() {
	int row;
	printf("Enter  number of rows that you want to display : ");
	scanf("%d", &row);
	
	for(int i=1; i<=row; i++) {
		for(int j=(row); j>=i; j--) {
			printf("*");
		}
		
		for(int k=1; k<i; k++) {
			printf(" ");
		}
		
		for(int m=1; m<i; m++) {
			printf(" ");
		}
		
		for(int l=(row); l>=i; l--) {
			printf("*");
		}
	
		printf("\n");
	}
	
	for(int i=1; i<=row; i++) {
		for(int j=1; j<=i; j++) {
			printf("*");
		}
		
		for(int k=i; k<row ; k++) {
			printf(" ");
		}
		
		for(int m=i; m<row; m++) {
			printf(" ");
		}
		
		for(int l=(1); l<=i; l++) {
			printf("*");
		}
	
		printf("\n");
	}
	
	return 0;
}
