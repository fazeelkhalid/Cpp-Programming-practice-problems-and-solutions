#include<stdio.h>

int main() {
	
	char ch;
	int array[5];
	int i = 0;
	int number;
	int condition = 0;
 	FILE *fp;

	fp = fopen("input.txt", "r");
	
	while((ch = fgetc(fp))!= EOF) {
		if(ch != ',') {

			if(!condition) {	
				array[i] = ch - 48;
				condition++;
			}
			else {
				array[i] = array[i] * 10 + (ch - 48);
			}
		}
		else {
			i++;
			condition = 0;
		}
	}
	
	fclose(fp);

	for(int i = 0; i < 5; i++) {
		
	}
	
	for(int i = 4; i >= 0; i--) {
		for(int j = i - 1; j >= 0; j--) {
			if(array[i]<array[j]) {
				number = array [i];
				array[i] = array[j];
				array[j] = number;	
			}
		}
	}
	
	for(int i = 0; i < 5; i++) {
		printf("%d\n",array[i]);
	}
	return 0;
}
