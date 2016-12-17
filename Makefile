CC   	:= gcc
CFLAGS  := -Wall -O0
LDFLAGS := -g 

all : tos_app

tos_app : tos_app.o libtos.a

libtos.a : tos.o
	ar rcs $@ $<

clean:
	rm -rf tos_app *.o *.a


