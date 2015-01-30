CC=g++
CFLAGS= -Wall -Wextra

SRC=src/main.cpp src/personnage/personnage.cpp src/personnage/weapon.cpp \
src/personnage/potion.cpp src/fight/fight.cpp src/list/list.cpp

SRCOBJ=src/main.o src/personnage/personnage.o src/personnage/weapon.o \
src/personnage/potion.o src/fight/fight.o src/list/list.o

OBJ=obj/main.o obj/personnage.o obj/weapon.o obj/potion.o obj/fight.o \
obj/list.o

norule:
	echo Specify all or clean

all: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o bin/FirstGame

clean: 
	rm -f obj/*.o
	rm -f bin/*
	rm -f src/*.o
	rm -f src/personnage/*.o
	rm -f src/fight/*.o
	rm -f src/list/*.o

$(OBJ): $(SRCOBJ) moveobj
	
moveobj:
	mv src/*.o obj/
	mv src/personnage/*.o obj/
	mv src/fight/*.o obj/
	mv src/list/*.o obj/
