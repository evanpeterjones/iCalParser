CC = g++
CFLAGS = -g -c -std=c++11
OBJS = ical.o
HEADERS = ical.h
APP_NAME = ical

easy:
	g++ ical.cpp -o ical -lcurl

all: $(APP_NAME)

$(APP_NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) -o $(APP_NAME)

ical: ical.o
	$(CC) $(CFLAGS) $< -o $@

ical.o: ical.cpp
	$(CC) $(CFLAGS) -c ical.cpp

clean:
	rm -f *.o
	rm -f *~
