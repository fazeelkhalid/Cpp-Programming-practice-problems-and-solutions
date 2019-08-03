#include<stdio.h>

int main() {
	int n = 5;
	int number[n];
	int index = 0;

	
	for(int index = 0; index < n; index++) {
		printf("Enter number : ");
		scanf("%d",&number[index]);
	}
	
	for(; index < n/2;) {
		if(number[index] == number [n-1-index]) 
			 index++;
		else
			break;
	}
	
	if(index == n/2 )
		printf("The array that you enter is a palindrome");
	else
		printf("The array that you enter is \"not\" a palindrome");
	return 0;
}

