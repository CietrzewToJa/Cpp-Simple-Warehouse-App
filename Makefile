CC = g++
EXEC = sfml-app

all: main.o Hero.o
	$(CC) main.o Hero.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	$(CC) main.cpp -c -o main.o

Hero.o: Hero.cpp
	$(CC) Hero.cpp -c -o Hero.o

run: $(EXEC)
	./$(EXEC)
