#include<stdio.h>

int main() {

 	FILE *fp;
 	fp = fopen("fazeelkhalid.txt","w");
 	fprintf(fp , "abcdefghijklmnopqrstuvwxyz");
 	
 	fclose(fp);
 	return 0;
}
