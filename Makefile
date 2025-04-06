.PHONY: watch-run run build default

# default: run
# default: run-sdl
default: run-sdl-cmake

build:
	mkdir -p bin
	gcc main.c -o bin/main -lX11

run: build
	./bin/main

watch-run:
	watchexec -r --stop-signal=SIGKILL -w Makefile -w main.c --debounce=5ms make run

build-sdl:
	mkdir -p bin
	gcc sdlwin.c -o bin/sdlwin -lSDL2

run-sdl: build-sdl
	./bin/sdlwin

build-sdl-cmake:
	mkdir -p build
	cd build && cmake .. -DCMAKE_POLICY_VERSION_MINIMUM=3.5 && make -j

run-sdl-cmake: build-sdl-cmake
	cd build && ./sdlwin_cmake
