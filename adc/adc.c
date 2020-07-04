#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ioctl.h>
#include<string.h>

int main()
{
	int fd = open("/dev/adc",2);
	char buffer[30];
	int len;
	if(fd < 0)
	{
		printf("cant open the file !! \n");
		exit(1);
	}

	while(1)
	{
		memset(buffer,0,sizeof(buffer-1));
		len = read(fd,buffer,sizeof(buffer-1));

		if(len > 0)
		{
			int value = -1;
			sscanf(buffer,"%s",&value);
			printf("ADC value = %d \n ",value);
		}
		else
			return 1;
	}




}




