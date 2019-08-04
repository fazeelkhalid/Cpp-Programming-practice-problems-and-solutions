#include <stdio.h>

int main()
	{
	   
	   FILE *fp;
	   char sentence[] = "FAZEEL KHALID";
	   
	   fp = fopen("write.txt", "w");
	   fprintf("%s", sentence);
	   fclose(fp);
	   
	   return 0;
	}
