CC=gcc -g
TARGET=WorkBot.c
RESULT=WorkBot
PKG_LIBS=`pkg-config --libs --cflags json-glib-1.0 gtk+-3.0`
OSFLAG 				:=
ifeq ($(OS),Windows_NT)

else
	INTERFACE_CONTROL=-lX11
endif

INCLUDES=-I include -rdynamic -g
CC_FLAGS=$(INCLUDES) $(PKG_LIBS) $(INTERFACE_CONTROL)
OBJECTS=main.o acao.o interpretador.o

all: objects.o

interpretador.o: src/interpretador.c
	$(CC) src/interpretador.c $(CC_FLAGS) -c

acao.o:src/acao.c
	$(CC) src/acao.c $(CC_FLAGS) -c

main.o: src/main.c
	$(CC) src/main.c $(CC_FLAGS) -c

objects.o: $(OBJECTS)
	$(CC) $(OBJECTS) $(TARGET) -o $(RESULT) $(CC_FLAGS)

clear:
	rm *.o
