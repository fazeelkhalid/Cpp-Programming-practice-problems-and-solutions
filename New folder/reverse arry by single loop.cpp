#include<stdio.h>

int main() {
	int a;
	int number[5];
	for(int i = 0; i < 5; i++) {
		printf("Enter number : ");
		scanf("%d",&number[i]);
	}
	
	for(int i = 0, j = 1; i < 5; i++,j++) {

		a = number[i];
		number[i] = number[j];
		number[j] = a;
		
	}
	
	for(int i = 0; i < 5; i++) {
		printf("%d",number[i]);
		printf(",");
	}

	
	return 0;
}
