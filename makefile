CC=g++
CFLAGS= -Wall -W -I ./includes

DEPNDECIES=
EXEC=run.out

dash:
	$(CC) $(CFLAGS) -o $(EXEC) dash.cpp
