TARGET = cpu_usage

SRCS = cpu_usage.c

KDIR = /lib/modules/$(shell uname -r)/build

EXTRA_CFLAGS = -O2 -Wall

obj-m += $(TARGET).o
$(TARGET)-objs := $(SRCS:.c=.o)

all:
    $(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
    $(MAKE) -C $(KDIR) M=$(PWD) clean
