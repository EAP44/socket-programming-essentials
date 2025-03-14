#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8000

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char buffer[1024] = {0};

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket error");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1 ||
        listen(server_socket, 3) == -1) {
        perror("Bind/Listen error");
        close(server_socket);
        return 1;
    }

    printf("Listening on port %d...\n", PORT);

    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_socket == -1) {
        perror("Accept error");
        close(server_socket);
        return 1;
    }

    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Client: %s\n", buffer);

    send(client_socket, "Hello from server!", 18, 0);

    close(client_socket);
    close(server_socket);
    return 0;
}

