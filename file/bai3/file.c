#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp;
	char c[] = "Example for function fread and fwrite";
	char buffer[100];

	/* Open file for both reading and writing */
	fp = fopen("test.txt", "rw");
	/* Write data to the file */
	fwrite(c, strlen(c) + 1, 1, fp);
	/* Seek to the beginning of the file */
	fseek(fp, SEEK_SET, 0);

	/* Read and display data */
	fread(buffer, strlen(c)+1, 1, fp);
	printf("%s\n", buffer);
	fclose(fp);
	return(0);
}
