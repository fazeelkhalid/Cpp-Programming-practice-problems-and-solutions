#include<stdio.h>


int main() {
	
	FILE  *file;
	char ch, ope;
	int first= 0, second= 0, result;
	bool is_first_number = true;
	bool is_second_number = true;
	
	file = fopen("input.txt", "r");
	
	while((ch = fgetc(file))!= EOF) {
	
		if(is_first_number) {
			if(ch>= '0' && ch<= '9') {		
				first= first * 10 + (ch - 48);
			}
		}
		
		else {
			if(ch>= '0' && ch<= '9')
			second= second * 10 + (ch - 48);
		}
		if(is_second_number) {	
			if(ch==37||ch==42||ch==43||ch==45||ch==47) {
				ope= ch;
				is_first_number = false;
				is_second_number = false;
			}
		}
		printf("%c is not a number\n",ch);
	}
	
	switch(ope) {
		case '-':
			result = first - second;
			printf("subtraction = %d", result);
			break;
			
		case '+':
			result = first + second;
			printf("sum = %d", result);
			break;
			
		case '*':
			result = first * second;
			printf("multiply = %d", result);
			break;
			
		case '/':
			result =first / second;
			printf("division = %d", result);
			break;
			
		case '%':
			result = first % second;
			printf("MOD = %d", result);
			break;
			
		default:
			printf("Please choose only \"SUM DIV MUL SUB MOD\" operation");			
	}
	
	return 0;
}
