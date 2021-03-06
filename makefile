src = src/*.cpp src/framework/*.cpp src/framework/ecs/*.cpp
args = -std=c++17 -pthread
libs = -lsfml-graphics -lsfml-window -lsfml-network -lsfml-audio -lsfml-system

make: debug run

debug:
	g++ $(src) -o bin/debug/run $(args) $(libs)

run:
	cd bin/debug; \
	./run

run-release:
	cd bin/release; \
	./run

build:
	g++ $(src) -o bin/release/run $(args) $(libs)

clean:
	rm bin/debug/run
	rm bin/release/run