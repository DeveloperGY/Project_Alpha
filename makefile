src = src/*.cpp src/framework/*.cpp
args = -std=c++17 -pthread
libs = -lsfml-graphics -lsfml-window -lsfml-system

make: debug run

debug:
	g++ $(src) -o bin/debug/run $(args) $(libs)

run:
	./bin/debug/run

build:
	g++ $(src) -o bin/release/run $(args) $(libs)

clean:
	rm bin/debug/run
	rm bin/release/run