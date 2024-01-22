CC = gcc
CFLAGS = -Wall -Wextra

# lista plikow .o
OBJECTS = func.o input.o main.o monte_carlo.o plot.o simpson.o data.o calculation_error.o
PNG = calka_wykres_monte.png calka_wykres_simpson.png 
TXT = plot_data_monte.txt plot_data_simpson.txt
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
	rm -f $(PNG) Monte_carlo
	rm -f $(TXT) Monte_carlo

run: Monte_carlo
	 ./Monte_carlo
