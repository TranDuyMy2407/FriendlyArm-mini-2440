#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char buffer[200];
	FILE *fp = fopen("test.txt","r");
	if(fp == NULL)
	{
		printf("cant open the file !!! \n");
		exit(-1);
	}

	else
	{
		memset(buffer,0,sizeof(buffer));
		if(fgets(buffer,100,fp) != NULL)
			puts(buffer);

		else
			fclose(fp);

	}
	return 0;
	

}
