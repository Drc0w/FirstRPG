CC=g++
CFLAGS=-Wall -Wextra

SRC=\
src/main.cpp src/personnage/personnage.cpp src/personnage/weapon.cpp \
src/personnage/potion.cpp src/fight/fight.cpp src/list/list.cpp \
src/personnage/spell.cpp

OBJ=\
obj/main.o obj/personnage.o obj/weapon.o obj/potion.o obj/fight.o \
obj/list.o obj/spell.o

norule:
	echo Specify all or clean

last: $(OBJ)
	$(CC) -o bin/FirstGame $^ $(CFLAGES)

all: clean 
all: last

clean: 
	rm -f obj/*.o
	rm -f bin/*
	rm -f src/*.o
	rm -f src/personnage/*.o
	rm -f src/fight/*.o
	rm -f src/list/*.o

$(OBJ):
	$(CC) -o obj/main.o -c src/main.cpp $(CFLAGS)
	$(CC) -o obj/personnage.o -c src/personnage/personnage.cpp $(CFLAGS)
	$(CC) -o obj/weapon.o -c src/personnage/weapon.cpp $(CFLAGS)
	$(CC) -o obj/potion.o -c src/personnage/potion.cpp $(CFLAGS)
	$(CC) -o obj/fight.o -c src/fight/fight.cpp $(CLAGS)
	$(CC) -o obj/list.o -c src/list/list.cpp $(CFLAGS)
	$(CC) -o obj/spell.o -c src/personnage/spell.cpp $(CFLAGS)

