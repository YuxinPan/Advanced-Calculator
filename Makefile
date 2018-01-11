calculator:  calculator.c
	gcc -o calculator calculator.c checkstr.c compute.c enotation.c  printerr.c priority.c  -lm

clean:
	$(RM) calculator $(objects) calculator.o checkstr.o compute.o enotation.o printerr.o priority.o
