#include <stdio.h>
#include<string.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PWM_IOCTL_SET_FREQ 1

#define PWM_IOCTL_STOP 0
#define ESC_KEY 0x1b

int fd , pwm_fd , i;
int freq = 1000;


char button[] = {'0','0','0','0','0','0'};
char current_button[] = {'0','0','0','0','0','0'};

void set_buzzer_freq(int fd, int freq)
{
	int ret = ioctl(fd, PWM_IOCTL_SET_FREQ, freq);
	if(ret < 0)
	{
		perror("set the frequency of the buzzer");
		exit(1);
	}
}
void stop_buzzer(int fd)
{
	int ret = ioctl(fd, PWM_IOCTL_STOP);
	if(ret < 0)
	{
		perror("stop the buzzer");
		exit(1);
	}
		close(fd);
}

int main(int argc, char **argv)
{

	fd = open("/dev/pwm", 0);

	if (fd < 0)
	{
		perror("open pwm_buzzer device");
		exit(1);
	}

	set_buzzer_freq(fd, freq);

	while( 1 )
	{

		pwm_fd  = open("/dev/pwm",0);
		if(pwm_fd < 0)
		{
			printf("cant open the file !!! \n");
			exit(-1);
		}


		int ret = read(pwm_fd , current_button,6);
		if(ret < 0)
		{
			printf("cant read the file !!! \n");
			exit(-1);
		}


		if(strcmp(button, current_button) != 0)
		{
			for(i = 1 ; i<6 ; i++)
			{
				if(current_button[i] == 1)
				{
					if(i == 1)
					{
						set_buzzer_freq(pwm_fd,freq+100);
						printf("key 1 duoc nhan, tan so +100hz \n");
					}
					else if(i == 2)
					{
						set_buzzer_freq(pwm_fd,freq+50);
						printf("key 2 duoc nhan, tan so +50hz \n");
					}
					else if(i == 3)
					{
						set_buzzer_freq(pwm_fd,freq-100);
						printf("key 3 duoc nhan, tan so -100hz \n");
					}
					else if(i == 4)
					{
						set_buzzer_freq(pwm_fd,freq-50);
						printf("key 4 duoc nhan, tan so -50hz \n");
					}
					else
					{
						printf("key 5 duoc nhan, stop buzzer !!! \n");
						stop_buzzer(pwm_fd);
					}
					
				}
			}
		}

	}
}
 
  	
