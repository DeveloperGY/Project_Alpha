src = src/*.cpp src/framework/*.cpp
args = -std=c++17
libs = -lsfml-graphics -lsfml-window -lsfml-system

make: debug run

debug:
	g++ $(src) -o bin/run $(args) $(libs)

run:
	./bin/run

build:
	g++ $(src) -o release/run $(args) $(libs)