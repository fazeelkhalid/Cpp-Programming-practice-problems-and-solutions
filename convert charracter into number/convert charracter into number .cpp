#include<stdio.h>
#include<conio.h>

int main() {
	char ch;
	
	printf("Enter any number that you eant to convert into number : ");
	scanf("%c", &ch);
	
	if(ch>='0' && ch<='9')
		printf("integer value of charracter %c = %d  ", ch, (ch-48));
	else 
		printf("please just enter number");
	
	return 0;
}
