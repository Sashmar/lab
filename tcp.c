#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
int main()
{
    int serversocket, clientsocket, port;
    struct sockaddr_in serveraddr, clientaddr;
    char message[50];
    struct serveraddr;
    socklen_t len;
    serversocket = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    printf("port number:");
    scanf("%d", &port);
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    bind(serversocket, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    bzero((char *)&clientaddr, sizeof(clientaddr));
    len = sizeof(clientaddr);
    listen(serversocket, 5);
    printf("\n waiting for client connection");
    printf("\n hai");
    clientsocket = accept(serversocket, (struct sockaddr *)&clientaddr, &len);
    printf(" \n reading message from client");
    read(clientsocket, message, sizeof(message));
    printf("\nmessage is %s", message);
    printf("\n Sending message to client");
    write(clientsocket, "YOUR MESSAGE RECIEVED", sizeof("YOUR MESSAGE RECIEVED"));
    close(clientsocket);
    close(serversocket);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
int main()
{
    int serversocket, clientsocket, port;
    struct sockaddr_in serveraddr, clientaddr;
    struct serveraddr;
    socklen_t len;
    char message[50];
    clientsocket = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *)&serveraddr, sizeof(serveraddr));
    len = sizeof(serveraddr);
    serveraddr.sin_family = AF_INET;
    printf("port number:");
    scanf("%d", &port);
    serveraddr.sin_port = htons(port);
    printf("\ntrying to connect to the server");
    connect(clientsocket, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    printf("\nConnected to server");
    printf("\n sending message to client");
    send(clientsocket, "HI I AM CLIENT", sizeof("HI I AM CLIENT"), 0);
    printf("\n Message recieving");
    recv(clientsocket, message, sizeof(message), 0);
    printf("\nmessage recieved is %s", message);
    close(clientsocket);
}