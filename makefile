CC=g++
PROJECT=tic-tac-toe
SRC=main.cpp game.cpp field.cpp
OBJ=$(SRC:.cpp=.o)
SFML_FLAGS=-lsfml-graphics -lsfml-window -lsfml-system

.PHONY: all

all: $(SRC) $(PROJECT)
	rm *.o

$(PROJECT): $(OBJ)
	$(CC) $(OBJ) -o $(PROJECT) $(SFML_FLAGS)

.cpp.o:
	$(CC) -c -Wall $< -o $@

clean:
	rm $(PROJECT)