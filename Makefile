CC = g++
EXEC = all
FILES = main.o item.o base.o states.o openstate.o app.o person.o

all: $(FILES)
	$(CC) $(FILES) -o all

main.o: main.cpp
	$(CC) main.cpp -c -o main.o

person.o: Person.cpp
	$(CC) Person.cpp -c -o person.o

item.o: Item.cpp
	$(CC) Item.cpp -c -o item.o

base.o: Base.cpp Item.cpp
	$(CC) Base.cpp -c -o base.o

states.o: States.cpp
	$(CC) States.cpp -c -o states.o

openstate.o: OpenState.cpp
	$(CC) OpenState.cpp -c -o openstate.o

app.o: App.cpp
	$(CC) App.cpp -c -o app.o

run: $(EXEC)
	./$(EXEC)
