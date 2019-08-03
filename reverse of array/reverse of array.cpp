#include<stdio.h>

int main() {
	int j;
	int number[5];
	int reverse[5];
	
	for(int i = 0; i < 5; i++) {
		printf("input numbers: ");
		scanf("%d", &number[i]);
	}
	
	for(int i = 4; i >= 0; i-- ) {
		if(j <5) {
			reverse[j] = number[i];
			j++;
		}
	}

	for(int i = 0; i < 5; i++) {
		number[i] = reverse[i];

	}
	
	for(int i = 0; i < 5; i++) {
		printf("%d",number[i]);
		printf(",");
	}

	return 0;

}
