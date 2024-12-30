CC = gcc
CFLAGS = -Wall -Wextra -g

SERVER_TARGET = udp_server
CLIENT_TARGET = udp_client

SERVER_SRC = udp_server.c
CLIENT_SRC = udp_client.c

all: server client

server:
	$(CC) $(CFLAGS) -o $(SERVER_TARGET) server/$(SERVER_SRC)

client:
	$(CC) $(CFLAGS) -o $(CLIENT_TARGET) client/$(CLIENT_SRC)

clean:
	rm -f $(SERVER_TARGET) $(CLIENT_TARGET)
