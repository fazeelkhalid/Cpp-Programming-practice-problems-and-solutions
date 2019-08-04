#include<stdio.h>
#include<conio.h>
int main()
{
	int i,a,b;
	printf("Enter number of lines that you want to display : ");
	scanf("%d",&b);
	for(i=1;i<=b;i++)
		{
		for(a=b;a>=i;a--)
			{
				printf("*");
			}
			printf("\n");
		}
		getch ();
	return 0;
}
