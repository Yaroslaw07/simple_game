.PHONY: all build clean run

all: build

build:
	mkdir -p build
	cd build && cmake ..
	cd build && make

clean:
	rm -rf build

run:
	./build/simple_game
