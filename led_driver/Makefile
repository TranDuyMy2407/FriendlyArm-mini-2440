obj-m = driver.o

KDIR = /lib/modules/2.6.32.2-FriendlyARM/build  M=$(PWD) 

all:
	make -C $(KDIR) modules

clean:
	make -C $(KDIR) clean

