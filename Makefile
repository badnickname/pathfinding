FLAGS = -Wall -lsfml-window -lsfml-system -lsfml-graphics

all: build

obj/main.o: main.cpp
	mkdir -p obj/
	g++ $(FLAGS) -c main.cpp -o obj/main.o

obj/window.o: src/window.cpp
	mkdir -p obj/
	g++ $(FLAGS) -c src/window.cpp -o obj/window.o

obj/cell.o: src/cell.cpp
	mkdir -p obj/
	g++ $(FLAGS) -c src/cell.cpp -o obj/cell.o

build: obj/main.o obj/window.o obj/cell.o
	mkdir -p obj/
	g++ $(FLAGS) obj/main.o obj/window.o obj/cell.o -o app

clean:
	rm obj/*.o

run:
	./app
