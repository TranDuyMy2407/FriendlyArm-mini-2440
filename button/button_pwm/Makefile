CC = arm-linux-gcc

button_pwm: button_pwm.o
	$(CC) -o $@ $<
button_pwm.o: button_pwm.c
	$(CC) -c $<

clean:
	rm *.o button_pwm

