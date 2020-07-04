#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
	int i;
	int led0 , led1, led2, led3;

	
	int fd = open("/dev/leds",2);
	if(fd < 0)
	{
		printf("cant open the file !! \n");
		exit(-1);	
	}

	while(1)
	{

		for(i = 0 ; i<16 ;i++ )
		{
			led0 = i%2;
			led1 = (i/2)%2;
			led2 = (i/4)%2;
			led3 = i/8;

			ioctl(fd,led0,0);
			ioctl(fd,led1,1);
			ioctl(fd,led2,2);
			ioctl(fd,led3,3);

			usleep(500000);
		}

	}

	close(fd);
	return 0;


}
