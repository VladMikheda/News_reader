PROJECT=ISA2022

CC = g++
#CFLAGS= -Wall -Wextra -pedantic
FILES=$(wildcard *.cpp)
LIB= -lcrypto -lssl
#ALL=$(wildcard *.cpp)

all: ISA2022 RUN

ISA2022:
	#g++ $(ALL) -o feedreader -lcrypto -lssl
	$(CC) $(CFLAGS) $(FILES) -o feedreader $(LIB)
RUN:
	./feedreader 'https://what-if.xkcd.com/feed.atom' -u -T