CC = arm-linux-gcc

button: button.o
	$(CC) -o $@ $<
button.o: button.c
	$(CC) -c $<

clean:
	rm *.o button

