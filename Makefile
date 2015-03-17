# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g

# the build target executable:
TARGET = main

$(TARGET): map.cpp
	$(CC) -o $(TARGET) map.cpp allstruct.c cursor.c video.c plotting.c rotasi.c drawing.c clip.c -lpthread
	./$(TARGET)

clean:
	$(RM) $(TARGET) 
