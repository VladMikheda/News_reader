PROJECT=ISA2022

CC = g++
#CFLAGS= -Wall -Wextra -pedantic
FILES=$(wildcard *.cpp)
LIB= -lcrypto -lssl -lxml2 -lz -llzma -licui18n -licuuc -licudata -lm
#ALL=$(wildcard *.cpp)

all: ISA2022 RUN

ISA2022:
	#g++ $(ALL) -o feedreader -lcrypto -lssl
	$(CC) $(CFLAGS) $(FILES) -o feedreader -I/usr/include/libxml2 $(LIB)
RUN:
	#./feedreader 'https://www.rssboard.org/files/sample-rss-092.xml' -u -T
	./feedreader 'https://en.wikipedia.org/w/api.php?hidebots=1&days=7&limit=50&hidewikidata=1&action=feedrecentchanges&feedformat=atom' -a -u -T