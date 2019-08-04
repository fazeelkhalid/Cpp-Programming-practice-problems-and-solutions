#include<stdio.h>
#include<conio.h>

int main() {
	char a[10];
	int b;
	
	printf("Enter any number that you want to assign to the integer : ");
	scanf("%s", &a);
	
	b=a[10];
	printf("%d",b);
	
	return 0;
}
