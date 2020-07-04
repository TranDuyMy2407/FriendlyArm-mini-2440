CC = arm-linux-gcc

pwm: pwm.o
	$(CC) -o $@ $<
pwm.o: pwm.c
	$(CC) -c $<

clean:
	rm *.o pwm

