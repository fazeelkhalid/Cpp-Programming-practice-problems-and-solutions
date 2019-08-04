#include<stdio.h>
#include<conio.h>

int main() {
	
	FILE  *b;
	char ch, ope= 'a';
	int first= 0, second= 0, a;
	bool is_first_number = true;
	
	b = fopen("input.txt", "r");
	
	while((ch = fgetc(b))!= EOF) {
		if(is_first_number) {
			if(ch>= '0' && ch<= '9') {		
				first= first * 10 + (ch - 48);
			}
		}
		else {
			second= second * 10 + (ch - 48);
		}
			
		if(ch>= 37 && ch<= 47) {
			ope= ch;
			is_first_number = false;
		}
	}
	
	switch(ope) {
		case '-':
			a = first - second;
			printf("subtraction = %d", a);
			break;
			
		case '+':
			a = first + second;
			printf("sum = %d", a);
			break;
			
		case '*':
			a = first * second;
			printf("multiply = %d", a);
			break;
			
		case '/':
			a =first / second;
			printf("division = %d", a);
			break;
			
		case '%':
			a = first % second;
			printf("MOD = %d", a);
			break;
			
		default:
			printf("Please choose only \"SUM DIV MUL SUB MOD\" operation");			
	}
	getch();
	
	return 0;
}
