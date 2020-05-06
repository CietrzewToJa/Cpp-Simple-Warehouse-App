CC = g++
EXEC = all

all: main.o item.o base.o
	$(CC) main.o item.o base.o -o all

main.o: main.cpp
	$(CC) main.cpp -c -o main.o

item.o: Item.cpp
	$(CC) Item.cpp -c -o item.o

base.o: Base.cpp Item.cpp
	$(CC) Base.cpp -c -o base.o

run: $(EXEC)
	./$(EXEC)
