CC = gcc
CFLAGS = -Wall -Wextra -O2

TARGET = catspeed

all:
	$(CC) $(CFLAGS) src/catspeed.c -o $(TARGET)

clean:
	rm -f $(TARGET)
