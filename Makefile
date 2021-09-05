CC=gcc
CFLAGS=-Wall -g -lm -lxml2 -lstdc++ -ldl -Iinclude/ -I/usr/include/libxml2 -fPIC
ENGSRC != find | grep -P -o ^\\./enginecode/\[^\\.\]+\\.cpp$
ENGOBJ=$(ENGSRC:.cpp=.o)


GAMESRC != find | grep -P -o ^\\./game/\[^\\.\]+\\.cpp$
GAMEOBJ=$(GAMESRC:.cpp=.o)

%.o: %.cpp $(DEPS)
	makedirs obj/$@
	$(CC) -c -o obj/$@ $< $(CFLAGS)

engine: $(ENGOBJ)
	cd obj;\
	$(CC) -o ../engine $^ $(CFLAGS)

game: $(GAMEOBJ)
	cd obj;\
	$(CC) -shared -o ../lib.so $^ $(CFLAGS)

all: engine game
