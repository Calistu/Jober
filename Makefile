CC=gcc -g
TARGET=WorkBot.c
RESULT=WorkBot
PKG_LIBS=`pkg-config --libs --cflags libxml-2.0 gtk+-3.0`
INCLUDES=-I include
CC_FLAGS=$(INCLUDES) $(PKG_LIBS)
OBJECTS=main.o acao.o

all: objects.o

acao.o:src/acao.c
	$(CC) src/acao.c $(CC_FLAGS) -c

main.o: src/main.c
	$(CC) src/main.c $(CC_FLAGS) -c

objects.o: $(OBJECTS)
	$(CC) $(OBJECTS) $(TARGET) -o $(RESULT) $(CC_FLAGS)

clear:
	rm *.o
