#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
int main()
{
    int clientsocket, serversocket, port;
    struct sockaddr_in serveraddr, clientaddr;
    struct serveraddr;
    socklen_t len;
    char message[50];
    serversocket = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    printf("port number:");
    scanf("%d", &port);
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    bind(serversocket, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    printf("\n waiting for client connection");
    bzero((char *)&clientaddr, sizeof(clientaddr));
    len = sizeof(clientaddr);
    recvfrom(serversocket, message, sizeof(message), 0, (struct sockaddr *)&clientaddr, &len);
    printf("\n connection recieved from client");
    printf("the message is %s", message);
    printf("\n sending message to client");
    sendto(serversocket, "YOUR MESSAGE RECIEVED", sizeof("YOUR MESSAGE RECIEVED"), 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));
    close(serversocket);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
int main()
{
    int clientsocket, serversocket, port;
    struct sockaddr_in serveraddr, clientaddr;
    struct serveraddr;
    socklen_t len;
    char message[50];
    clientsocket = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&serveraddr, sizeof(serveraddr));
    len = sizeof(serveraddr);
    serveraddr.sin_family = AF_INET;
    printf("\nport number:");
    scanf("%d", &port);
    serveraddr.sin_port = htons(port);
    printf("\n sending message for server connection ");
    sendto(clientsocket, "HI I  AM CLIENT", sizeof("HI I AM CLIENT"), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    printf("\n recieving message from client");
    recvfrom(clientsocket, message, sizeof(message), 0,
             (struct sockaddr *)&serveraddr, &len);
    printf("\n the message recieved is %s\n", message);
    close(serversocket);
}