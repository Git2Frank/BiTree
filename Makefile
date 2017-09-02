CC     = gcc
TARGET = BiTree.exe
OBJS   = main.o BiTree.o

ifeq ($(debug),y)
	CFLAGS += -D DEBUG -g
endif

.PHONY: all clean

$(TARGET):	$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(TARGET)

all: $(TARGET)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

BiTree.o: BiTree.c
	$(CC) -c BiTree.c -o BiTree.o $(CFLAGS)
	
clean: 
	rm -f $(OBJS)
	rm -f $(TARGET)
