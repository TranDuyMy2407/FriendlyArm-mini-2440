#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char buffer[200];
	char *c = "hello world !!! \n";
        int i;

	FILE *fp = fopen("test.txt","w");
	memset(buffer,0,sizeof(buffer));

	if(fp == NULL)
	{
		printf("cant open the file !! \n");
		exit(-1);
	}

	else
	{
		fwrite(c,strlen(c)+1,1,fp);
		fseek(fp,SEEK_SET,0);
	}

	fp=fopen("test.txt","r");
	if(fp == NULL)
	{
		printf("cant open the file !!! \n");
		exit(-1);
	}

	int ret = fread(buffer,strlen(c)+1,1,fp);
	if(ret < 0)
	{
		printf("cant read the file !!! \n");
		exit(-1);
	}

	printf("%s\n",buffer);
	fclose(fp);

	return 0;
}

