args = -std=c++17
libs = -lsfml-graphics -lsfml-window -lsfml-system

make: debug run

debug:
	g++ src/*.cpp -o bin/run $(args) $(libs)

run:
	./bin/run

rel:
	g++ src/*.cpp -o release/run $(args) $(libs)