#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


int main() {
    int cs;
    struct sockaddr_in sa;
    char *message = "Hello from the Linux TCP Client!";
    char msg[1024] = {0};

    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit();
    }

    // Configure server address
    sa.sin_family = AF_INET;
    sa.sin_port = htons(3000);
    if (inet_pton(AF_INET, "127.0.0.1", &sa.sin_addr) <= 0) {
        perror("Invalid address or Address not supported");
        close(client_socket);
        exit();
    }

    // Connect to the server
    if (connect(cs, (struct sockaddr *)&sa, sizeof(sa)) == -1) {
        perror("Connection failed");
        close(cs);
        exit();
    }

    // Send a message to the server
    if (send(client_socket, message, strlen(message), 0) == -1) {
        perror("Send failed");
        close(client_socket);
        exit();
    }
    printf("Message sent to server.\n");

    // Receive the server's response
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Receive failed");
        close(client_socket);
        exit(EXIT_FAILURE);
    }
    printf("Server: %s\n", buffer);

    // Close the socket
    close(client_socket);

    return 0;
}
