CC = g++

LIBS =
CFLAGS = -Wall -std=c++11
OBJECTS = main.o
HFILES = singlelist.h
TARGET = main.exe

%.o : %.cpp $(HFILES) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS) -o $(TARGET)

.PHONY : clean

clean :
	$(RM) $(TARGET) *.o core