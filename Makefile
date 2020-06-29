.PHONY:clean

all: server client

server: server.cpp
	g++ server.cpp -o server -lpthread

client: client.c
	gcc client.c -o client

clean:
	rm -rf *.o client server
