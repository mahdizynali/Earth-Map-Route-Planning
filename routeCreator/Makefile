CC = g++
CFLAGS  = -g -Wall
RM = rm

OPENCV = `pkg-config --cflags --libs opencv4`

lIBS = $(OPENCV)

all: main run

main: main.o map.o
	$(CC) $(CFLAGS) -o main main.o map.o $(lIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $< $(lIBS)

run:
	./main
clean:
	rm *.o main
