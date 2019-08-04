#include<stdio.h>
#include<conio.h>

int main() {
	int a, b, c, d;
	printf("enter number of rows you want to display : ");
	scanf("%d", &d);
	
	for(a=1; a<=d; a++) {
		for(c=d; c>a; c--) {
			printf(" ");
		}
		
		for(b=1; b<=a; b++) {
			printf("*");
		}
		
		printf("\n");
	}
	
	return 0;
}
