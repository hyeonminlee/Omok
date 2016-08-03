CC = gcc
CFLAGS = -g -Wall
SOURCE = main.c conio.c omokfunction.c
HEADER = conio.h omokfunction.h
TARGET = omok

.PHONY: clean

$(TARGET) : $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean :
	rm -f $(TARGET) 
