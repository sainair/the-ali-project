C= g++
srcdir = src
src = $(srcdir)/main.cpp
lib = lib
cf = -lsfml-graphics -lsfml-window -lsfml-system -o
of = -c -o
obj = $(srcdir)/$(lib)/main.o

mainobj:
	$(C) $(of) $(obj) $(src)

bin = bin
target = $(srcdir)/$(bin)/ali

main: $(obj)
	$(C) $(cf) $(target) $(obj)

runC:
	./$(target)

arch-dependencies:
	pacman -S sfml

deb-dependencies:
	apt install libsfml-dev

all: mainobj main runC
