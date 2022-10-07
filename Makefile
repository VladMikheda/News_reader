PROJECT=ISA2022

CC = g++
#CFLAGS= -Wall -Wextra -pedantic
FILES=$(wildcard *.cpp)
LIB=-lpcap -lcrypto -lssl

all: ISA2022 RUN

ISA2022:
	$(CC) $(CFLAGS) $(FILES) -o feedreader $(LIB)
RUN:
	./feedreader 'https://what-if.xkcd.com?sasa=asa' -u -T