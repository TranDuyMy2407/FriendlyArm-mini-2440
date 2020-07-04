#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	int button_fd,led_fd,i, level, c;
	int button_read;
	int flag = 0;

	char button[6] = {'0', '0' , '0' , '0' , '0' , '0'};
	button_fd = open("/dev/buttons",2);
	if(button_fd < 0)
	{
		printf("cant open the file !!! \n");
		exit(-1);
	}

	while(1)
	{
		usleep(200000);
		int led_fd = open("/dev/leds",2);
		button_read = read(button_fd,button,6);

		for(i = 0 ; i< 4 ; i++)
			ioctl(led_fd,0,i);

		for(i = 0 ;i < 4 ; i++)
		{
			if(button[i] != 0)
			{
				flag = !flag;
				ioctl(led_fd,flag,i);
				
			}

		}
			flag = button[i];

	}

	close(button_fd);
	close(led_fd);



}


