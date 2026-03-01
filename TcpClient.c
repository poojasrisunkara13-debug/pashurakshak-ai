#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>   // for close()

#define PORT 4444

int main() {

    int clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[1024];
    int bytesReceived;

    // Create socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        perror("[-]Socket creation failed");
        exit(1);
    }
    printf("[+]Client Socket Created Successfully.\n");

    // Configure server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("[-]Connection Failed");
        exit(1);
    }
    printf("[+]Connected to Server.\n");

    // Receive data
    bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
    if (bytesReceived < 0) {
        perror("[-]Receive failed");
    } else {
        buffer[bytesReceived] = '\0';   // Null terminate
        printf("[+]Data Received: %s\n", buffer);
    }

    printf("[+]Closing the connection.\n");
    close(clientSocket);

    return 0;
}