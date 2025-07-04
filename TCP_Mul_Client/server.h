#ifndef SERVER_H
#define SERVER_H

#define PORT 8888
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 30
#define WELCOME_MESSAGE "Welcome!"

void initialize_server(int *server_socket, struct sockaddr_in *server_addr);
void handle_new_connection(int server_socket, int client_sockets[], fd_set *readfds, struct sockaddr_in *client_addr);
void handle_client_activity(int client_sockets[], fd_set *readfds);

#endif
