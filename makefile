args = -lsfml-graphics

make: build run

build:
	g++ src/*.cpp -o bin/run $(args)

run:
	./bin/run