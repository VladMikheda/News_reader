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
	./feedreader 'https://en.wikipedia.org/w/api.php?hidebots=1&days=7&limit=50&hidewikidata=1&action=feedrecentchanges&feedformat=atom' -u -T