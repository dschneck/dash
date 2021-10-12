CC=g++
CFLAGS= -Wall -W -I ./includes

EXEC=run.out

dash:
	$(CC) $(CFLAGS) -o $(EXEC) dash.cpp
