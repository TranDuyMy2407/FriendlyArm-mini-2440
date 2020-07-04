CC = arm-linux-gcc

dem_nhi_phan: dem_nhi_phan.o
	$(CC) -o $@ $<
dem_nhi_phan.o: dem_nhi_phan.c
	$(CC) -c $<


clean:
	rm  *.o dem_nhi_phan
