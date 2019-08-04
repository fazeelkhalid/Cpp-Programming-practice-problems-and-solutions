#include<stdio.h>

int main() {
	
	FILE  *file;
	char ch;
	char ope;
	int first = 0;
	int second = 0;
	int result;
	bool is_first_number = true;
	bool operator_variable = true;
	bool error_condition = true;
	
	file = fopen("input.txt", "r");
	
	while((ch = fgetc(file))!= EOF) {
		
		if(is_first_number) {
			
			if(ch>= '0' && ch<= '9') {		
				first= first * 10 + (ch - 48);
			}
		}
		else if(ch>= '0' && ch<= '9') {
			second= second * 10 + (ch - 48);	
		}
		
		if(ch=='-' || ch=='+' || ch=='*' || ch=='/' || ch=='%') {
			if(operator_variable) {
				ope= ch;
				is_first_number = false;
				operator_variable = false;
			}
			else {
				printf("Wrong input");
				error_condition = false;
				break;	
			}
		}
		else if(ch < '0' || ch > '9') {
			printf("Wrong input");
			error_condition = false;
			break;
		}
	
	}
	
	if(error_condition) {
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
			
		}
	}
	
	fclose(file);
	return 0;
}
