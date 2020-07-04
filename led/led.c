#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ioctl.h>
#include<sys/fcntl.h>

int main()
{
	int fd = open("/dev/leds", 0);
	if(fd < 0)
	{
		printf("khong the mo file !!! \n");
		exit(1);
	}
	

	while(1)
	{
		

		ioctl(fd,0,0);
		ioctl(fd,0,1);
		ioctl(fd,0,2);
		ioctl(fd,0,3);

		sleep(40000);
		ioctl(fd,1,0);
		usleep(400000);
		ioctl(fd,1,1);
		usleep(400000);
		ioctl(fd,1,2);
		usleep(400000);
		ioctl(fd,1,3);
	}

	close(fd);
	return 0;

}
