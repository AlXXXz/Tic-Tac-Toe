LIBS=-lsfml-window -lsfml-graphics -lsfml-system
NAME=tic-tac

all: $(NAME)

$(NAME): main.o 
	g++ main.o $(LIBS) -o $(NAME)

main.o: main.cpp
	g++ -c main.cpp -o main.o 

clean: 
	rm main.o $(NAME)