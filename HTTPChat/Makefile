TARGET = server
CC = gcc

PREF_OBJ = ./obj/
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, $(PREF_OBJ)%.o, $(SRC))

all: $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(PREF_OBJ)%.o : %.c
	$(CC) -c $< -o $@

clear:
	rm $(TARGET) $(PREF_OBJ)*.o