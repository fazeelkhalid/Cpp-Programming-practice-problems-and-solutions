#include<stdio.h>
#include<conio.h>

int main() {
	int num;
	
	printf("Enter any letter that you want to test : ");
	scanf("%c",&num);
	
	if(num>='A' && num<='Z') 
		printf("you entered an upper case letter that is %c",num);
	else if (num>='a' && num<'=z') 
		printf("you entered an lower case letter that is %c",num);
	else 
		printf("you entered a number, special symbol or blank space");
	
	return 0;
	
}
