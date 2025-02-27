#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <netinet/in.h>
#include "server.h"

int main() {
    int server_socket, max_sd, activity, sd;
    struct sockaddr_in server_addr, client_addr;
    int client_sockets[MAX_CLIENTS] = {0};
    fd_set readfds;

    initialize_server(&server_socket, &server_addr);

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(server_socket, &readfds);
        max_sd = server_socket;

        // Add client sockets to the set
        for (int i = 0; i < MAX_CLIENTS; i++) {
            sd = client_sockets[i];
            if (sd > 0) FD_SET(sd, &readfds);
            if (sd > max_sd) max_sd = sd;
        }

        // Wait for activity
        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);
        if (activity < 0) {
            perror("Select error");
            continue;
        }

        // Handle new connections
        if (FD_ISSET(server_socket, &readfds)) {
            handle_new_connection(server_socket, client_sockets, &readfds, &client_addr);
        }

        // Handle client activity
        handle_client_activity(client_sockets, &readfds);
    }

    return 0;
}
