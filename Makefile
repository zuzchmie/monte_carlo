CC = gcc
CFLAGS = -Wall -Wextra

# lista plikow .o
OBJECTS = func.o input.o main.o monte_carlo.o plot.o simpson.o data.o

all: Monte_carlo

# linkowanie
Monte_carlo: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# kompilowanie
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# czyszczenie
clean:
	rm -f $(OBJECTS) Monte_carlo

run: Monte_carlo
	./Monte_carlo