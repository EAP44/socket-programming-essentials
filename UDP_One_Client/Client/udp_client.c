#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define SERVER_IP "127.0.0.1"
#define CLIENT_MESSAGE "Hello from the UDP Client!"

int main() {
    int client_socket;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);

    if ((client_socket = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address or Address not supported");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    // Send message to server
    sendto(client_socket, CLIENT_MESSAGE, strlen(CLIENT_MESSAGE), 0, (struct sockaddr *)&server_addr, addr_len);
    printf("Message sent to server.\n");

    // Receive response from server
    int n = recvfrom(client_socket, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, &addr_len);
    if (n < 0) {
        perror("Receive failed");
    } else {
        buffer[n] = '\0'; // Null-terminate the received data
        printf("Server: %s\n", buffer);
    }

    close(client_socket);
    return 0;
}
