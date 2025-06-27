.PHONY: build release

build:
	cmake -DCMAKE_BUILD_TYPE=Debug -B build
	make -C build

release:
	cmake -DCMAKE_BUILD_TYPE=Release -B release
	make -C release

run:
	./build/SDLconway

run_release:
	./release/SDLconway
