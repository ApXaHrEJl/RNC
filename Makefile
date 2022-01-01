all: bin/game

bin/game: obj/main.o obj/drawing.o obj/gfx.o obj/game_cycle.o obj/buttons.o obj/system.o
	mkdir bin
	g++ -Wall -Werror obj/main.o obj/gfx.o obj/game_cycle.o obj/buttons.o obj/system.o obj/drawing.o -o bin/game -lX11
	mkdir userdata

obj/buttons.o: src/buttons.cpp 
	g++ -I include -Wall -Werror -c src/buttons.cpp -o obj/buttons.o -lX11

obj/system.o: src/system.cpp 
	g++ -I include -Wall -Werror -c src/system.cpp -o obj/system.o -lX11

obj/game_cycle.o: src/game_cycle.cpp 
	g++ -I include -Wall -Werror -c src/game_cycle.cpp -o obj/game_cycle.o -lX11

obj/drawing.o: src/drawing.cpp 
	g++ -I include -Wall -Werror -c src/drawing.cpp -o obj/drawing.o -lX11

obj/gfx.o: src/gfx.cpp 
	g++ -I include -Wall -Werror -c src/gfx.cpp -o obj/gfx.o -lX11

obj/main.o: src/main.cpp
	mkdir obj
	g++ -I include -Wall -Werror -c src/main.cpp -o obj/main.o -lX11

clean:
	rm -rf bin/ obj/ userdata/

run:
	./bin/game

PHONY: all clean
