#include<stdio.h>
#include<conio.h>
int main() {
	int i,a,b;
	printf("enter number of rows you want to display : ");
	scanf("%d",&b);
	for(i=1;i<=b;i++)
	{
		for(a=1;a<=i;a++)
		{
			printf("*");
		}
		printf("\n");	
	}
	return 0;
}
