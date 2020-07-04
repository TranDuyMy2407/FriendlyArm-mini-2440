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

int fd , pwm_fd , i,j;
int freq = 1000;

char button[] = {'0','0','0','0','0','0'};
char current_button[] = {'0','0','0','0','0','0'};

void set_buzzer_freq(int fd, int freq)
{
	int ret = ioctl(fd, PWM_IOCTL_SET_FREQ, freq);
}
void stop_buzzer(int fd)
{
	int ret = ioctl(fd, PWM_IOCTL_STOP);
		close(fd);
}

int main(int argc, char **argv)
{

	int led_fd = open("/dev/leds",2);
	int button_fd = open("/dev/buttons",2);
	pwm_fd  = open("/dev/pwm",2);
	if (fd < 0)
	{
		perror("open pwm_buzzer device");
		exit(1);
	}


	while( 1 )
	{
		if(pwm_fd < 0)
		{
			printf("cant open the file !!! \n");
			exit(-1);
		}


		int ret = read(button_fd , current_button,6);
		if(ret < 0)
		{
			printf("cant read the file !!! \n");
			exit(-1);
		}


		if(strcmp(button, current_button) != 0)
		{
			for(i = 0 ; i<=3 ; i++)
			{
				if(current_button[i] == '1')
				{
					if(i == 0)
					{
						ioctl(led_fd,0,0);
						ioctl(led_fd,0,1);
						ioctl(led_fd,0,2);
						ioctl(led_fd,0,3);

						ioctl(led_fd,1,0);

						pwm_fd = open("/dev/pwm",2);

						set_buzzer_freq(pwm_fd,500);
						usleep(300);

						stop_buzzer(pwm_fd);
						ioctl(led_fd,1,0);

					}
					else if(i == 1)
					{
						ioctl(led_fd,0,0);
                                                ioctl(led_fd,0,1);
                                                ioctl(led_fd,0,2);
                                                ioctl(led_fd,0,3);

						ioctl(led_fd,1,0);
						ioctl(led_fd,1,1);
						for(j = 0 ; j< 2; j++)
						{
							pwm_fd = open("/dev/pwm",2);
							set_buzzer_freq(pwm_fd,1000);
							usleep(300000);
							stop_buzzer(pwm_fd);
							usleep(300000);
						}
						
					}
					else if(i == 2)
					{

						ioctl(led_fd,0,0);
                                                ioctl(led_fd,0,1);
                                                ioctl(led_fd,0,2);
                                                ioctl(led_fd,0,3);

						ioctl(led_fd,1,0);
						ioctl(led_fd,1,1);
						ioctl(led_fd,1,2);

						for(j = 0 ; j<3; j++)
						{
							pwm_fd = open("/dev/pwm",2);
							set_buzzer_freq(pwm_fd,1500);
							usleep(300000);
							stop_buzzer(pwm_fd);
							usleep(300000);

						}
					}
					else if(i == 3)
					{
						ioctl(led_fd,0,0);
                                                ioctl(led_fd,0,1);
                                                ioctl(led_fd,0,2);
                                                ioctl(led_fd,0,3);

						ioctl(led_fd,1,0);
						ioctl(led_fd,1,1);
						for(j = 0 ; j<4 ; j++)
						{
							pwm_fd = open("/dev/pwm",2);
							set_buzzer_freq(pwm_fd,2000);
							usleep(300000);
							stop_buzzer(pwm_fd);
							usleep(300000);

						}
					}
					
				}
			}
		}

	}
}
 
  	
