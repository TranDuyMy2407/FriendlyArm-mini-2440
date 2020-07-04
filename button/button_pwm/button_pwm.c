#include<stdio.h>
#include<termios.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ioctl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define PWM_IOCTL_SET_FREQ 1
#define PWM_IOCTL_STOP 0
#define ESC_KEY 0x1b

void set_buzzer_freq(int fd, int freq)
{
	// this IOCTL command is the key to set frequency
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


int main()
{
	int button_fd,led_fd,i=0, level, c;
	int button_read;
	int freq = 1000;
	char button[6] = {'0','0','0','0','0','0'};
	char current_button[6] = {'0','0','0','0','0','0'};

	button_fd = open("/dev/buttons",2);
	if(button_fd < 0)
	{
		printf("cant open the file !!! \n");
		exit(-1);
	}

	int pwm_fd = open("/dev/pwm",2);

	while(1)
	{
		if(i > 5)
			i = 0;

		button_read = read(button_fd,current_button,6);
		if(strcmp(button,current_button) !=  0)
		{	
			for(i = 0 ; i< 6 ; i++)
			{
				if(a[i] == '1')
					
			if(i == 1)
				set_buzzer_freq(pwm_fd,freq+100);

			else if(i == 2)
                	        set_buzzer_freq(pwm_fd,freq+50);

			else if(i == 3)
                	         set_buzzer_freq(pwm_fd,freq-100);

			else if(i == 4)
                	         set_buzzer_freq(pwm_fd,freq-50);

			else if(i == 5)
				stop_buzzer(pwm_fd);

		i++;
				
		}
	memset(button,'0',6);

	}
}


