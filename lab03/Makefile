obj-m += Module_a.o
obj-m += Module_b.o
obj-m += Module_c.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean: 
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
