CC=gcc
TARGET=WorkBot.c
RESULT=WorkBot
GCC_FLAGS=-Wall -Wstrict-prototypes -Wmissing-prototypes -Wshadow -Wconversion -g
PKG_LIBS=`pkg-config --libs --cflags json-glib-1.0 gtk+-3.0`
OSFLAG 				:=
ifeq ($(OS),Windows_NT)

else
	INTERFACE_CONTROL=-lX11
endif

INCLUDES=-I include -rdynamic -g
CC_FLAGS=$(INCLUDES) $(PKG_LIBS) $(INTERFACE_CONTROL) $(GCC_FLAGS)
OBJECTS=main.o acao.o interpretador.o tarefa.o params.o analise.o

all: objects.o

analise.o: src/analise.c
	$(CC) src/analise.c $(CC_FLAGS) -c

params.o: src/params.c
	$(CC) src/params.c $(CC_FLAGS) -c

interpretador.o: src/interpretador.c
	$(CC) src/interpretador.c $(CC_FLAGS) -c

tarefa.o: src/tarefa.c
	$(CC) src/tarefa.c $(CC_FLAGS) -c

acao.o:src/acao.c
	$(CC) src/acao.c $(CC_FLAGS) -c

main.o: src/main.c
	$(CC) src/main.c $(CC_FLAGS) -c

objects.o: $(OBJECTS)
	$(CC) $(OBJECTS) $(TARGET) -o $(RESULT) $(CC_FLAGS)

clear:
	rm *.o
