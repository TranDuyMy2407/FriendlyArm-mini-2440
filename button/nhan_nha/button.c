#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	int button_fd,led_fd,i, level, c;
	int button_read;
	int flag = 0;
	char button[6] = {'0','0','0','0','0','0'};

	button_fd = open("/dev/buttons",2);
	if(button_fd < 0)
	{
		printf("cant open the file !!! \n");
		exit(-1);
	}

	char current_button[6] = {'0', '0' , '0' , '0' , '0' , '0'};
	while(1)
	{
		int led_fd = open("/dev/leds",2);
		usleep(200000);
		button_read = read(button_fd,button,6);

		for(i = 0 ; i< 4 ; i++)
			ioctl(led_fd,0,i);

		for(i = 0 ;i < 6 ; i++)
		{
			if(current_button[i] != button[i])
			{
				if(button[i] == '0')
				{
					flag = 0;
					led_fd = open("/dev/leds",2);
					ioctl(led_fd,flag,i);
				}

				else
				{
					flag = 1;
					led_fd = open("/dev/leds",2);
					ioctl(led_fd,flag,i);
				}
				


			}		


		}

	}

	close(button_fd);
	close(led_fd);



}


