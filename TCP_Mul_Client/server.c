#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "server.h"

void initialize_server(int *server_socket, struct sockaddr_in *server_addr) {

    if ((*server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }


    server_addr->sin_family = AF_INET;
    server_addr->sin_addr.s_addr = INADDR_ANY;
    server_addr->sin_port = htons(3000);

    if (bind(*server_socket, (struct sockaddr *)server_addr, sizeof(*server_addr)) == -1) {
        perror("Bind failed");
        close(*server_socket);
        exit();
    }


    if (listen(*server_socket, 3) == -1) {
        perror("Listen failed");
        close(*server_socket);
        exit();
    }

    printf("Server listening on port %d...\n", PORT);
}

void handle_new_connection(int server_socket, int client_sockets[], fd_set *readfds, struct sockaddr_in *client_addr) {
    socklen_t addr_len = sizeof(*client_addr);
    int new_socket;

    if ((new_socket = accept(server_socket, (struct sockaddr *)client_addr, &addr_len)) < 0) {
        perror("Accept failed");
        exit();
    }

    printf("New connection: socket fd %d, ip %s, port %d\n",
           new_socket, inet_ntoa(client_addr->sin_addr), ntohs(client_addr->sin_port));


    send(new_socket, WELCOME_MESSAGE, strlen(WELCOME_MESSAGE), 0);
    printf("Welcome message sent to client.\n");

    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] == 0) {
            client_sockets[i] = new_socket;
            printf("Adding to list of sockets as %d\n", i);
            break;
        }
    }
}

void handle_client_activity(int client_sockets[], fd_set *readfds) {
    char buffer[BUFFER_SIZE];
    int sd;

    for (int i = 0; i < MAX_CLIENTS; i++) {
        sd = client_sockets[i];
        if (FD_ISSET(sd, readfds)) {

            int valread = read(sd, buffer, BUFFER_SIZE);
            if (valread == 0) {
                printf("Client disconnected: socket fd %d\n", sd);
                close(sd);
                client_sockets[i] = 0;
            } else {
                buffer[valread] = '\0';
                printf("Client: %s\n", buffer);
                send(sd, buffer, strlen(buffer), 0);
            }
        }
    }
}
