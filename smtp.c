#include <stdio.h>

#include <string.h>

#include <sys/types.h>

#include <netinet/in.h>

#include <netdb.h>

#define cls() printf("\033[H\033[J") int main()

{

    int clientsocket, port;

    struct sockaddr_in serveraddr;
    socklen_t len;

    struct hostent *server;
    char from[50];

    char to[50];
    char mail[100];

    char request[50];

    clientsocket = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&serveraddr, sizeof(serveraddr));

    serveraddr.sin_family = AF_INET;

    printf("Enter the port number ");

    scanf("%d", &port);

    serveraddr.sin_port = htons(port);

    // server=gethostbyname("127.0.0.1");

    // bcopy((char*)server->h_addr,(char*)&serveraddr.sin_addr.s_addr,sizeof(server->h_addr));

    len = sizeof(serveraddr);

    printf("\nEnter the FROM address:\n");
    fgets(from, sizeof(from), stdin);
    fgets(from, sizeof(from), stdin);

    printf("\n");

    printf("\nEnter the TO address:\n");

    fgets(to, sizeof(to), stdin);

    printf("\nEnter the MAIL:\n");

    fgets(mail, sizeof(mail), stdin);

    cls();

    printf("\nPRESS ENTER TO BEGIN THE FIRST PROCESS.\n");

    fgets(request, 2, stdin);

    printf("\nSending SMTP REQUEST to the server.\n");

    strcpy(request, "SMTP REQUEST.");
    sendto(clientsocket, request, sizeof(request), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

    printf("\nWaiting for the server response.\n");

    recvfrom(clientsocket, request, sizeof(request), 0, (struct sockaddr *)&serveraddr, &len);
    cls();

    printf("\nThe server has send:\t%s\n", request);

    printf("\nPRESS ENTER TO SEND THE FIRST COMMAND.\n");

    fgets(request, 2, stdin);

    printf("\nSending the HELO command\n") strcpy(request, "HELO");
    sendto(clientsocket, request, sizeof(request), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

    printf("\nWaiting for the server response.\n");

    recvfrom(clientsocket, request, sizeof(request), 0, (struct sockaddr *)&serveraddr, &len);
    cls();

    printf("\nThe server has send:\t%s\n", request);

    printf("\nPRESS ENTER TO BEGIN THE SECOND COMMAND.\n");

    fgets(request, 2, stdin);

    printf("\nSending the MAIL FROM request.\n");

    strcpy(request, "MAIL FROM:");

    strcat(request, from);

    sendto(clientsocket, request, sizeof(request), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    printf("\nWaiting for the server response.\n");

    recvfrom(clientsocket, request, sizeof(request), 0, (struct sockaddr *)&serveraddr, &len);
    cls();

    printf("\nThe server has send:\t%s\n", request);

    printf("\nPRESS ENTER TO BEGIN THE THIRD COMMAND.\n");

    fgets(request, 2, stdin);

    printf("\nSending the RCPT TO request.\n");

    strcpy(request, "RCPT TO:");

    strcat(request, to);

    sendto(clientsocket, request, sizeof(request), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    printf("\nWaiting for the server response.\n");

    recvfrom(clientsocket, request, sizeof(request), 0, (struct sockaddr *)&serveraddr, &len);
    cls();

    printf("\nThe server has send:\t%s\n", request);

    printf("\nPRESS ENTER TO BEGIN THE FOURTH COMMAND.\n");

    fgets(request, 2, stdin);

    printf("\nSending the DATA request.\n");

    strcpy(request, "DATA:");
    sendto(clientsocket, request, sizeof(request), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

    printf("\nWaiting for the server response.\n");

    recvfrom(clientsocket, request, sizeof(request), 0, (struct sockaddr *)&serveraddr, &len);
    cls();

    printf("\nThe server has send:\t%s\n", request);

    printf("\nPRESS ENTER TO BEGIN SENDING THE MAIL.\n");

    fgets(request, 2, stdin);
    printf("\nSending the mail.\n");

    strcpy(request, mail);

    sendto(clientsocket, request, sizeof(request), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

    printf("\nWaiting for the server response.\n");

    recvfrom(clientsocket, request, sizeof(request), 0, (struct sockaddr *)&serveraddr, &len);
    cls();

    printf("\nThe server has send:\t%s\n", request);

    printf("\nPRESS ENTER TO BEGIN THE LAST COMMAND.\n");

    fgets(request, 2, stdin);

    printf("\nSending the QUIT request.\n");
    strcpy(request, "QUIT:");

    sendto(clientsocket, request, sizeof(request), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    printf("\nWaiting for the server response.\n");

    recvfrom(clientsocket, request, sizeof(request), 0, (struct sockaddr *)&serveraddr, &len);
    cls();

    printf("\nThe server has send:\t%s\n", request);
    printf("\n\nCLIENT CLOSING DOWN.\n\n");
}

#include <stdio.h>

#include <string.h>

#include <sys/types.h>

#include <netinet/in.h>

#include <netdb.h>

#define cls()

printf("\033[H\033[J");
int main()

{

    int serversocket, port;

    struct sockaddr_in serveraddr, clientaddr;

    socklen_t len;

    char request[50];
    char from[50];
    char to[50];

    char mail[100];
    serversocket = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;

    printf("Enter the port number ");
    scanf("%d", &port);

    serveraddr.sin_port = htons(port);

    serveraddr.sin_addr.s_addr = INADDR_ANY;
    bind(serversocket, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    bzero((char *)&clientaddr, sizeof(clientaddr));

    len = sizeof(clientaddr);
    cls();

    printf("\nWaiting for the request from the client.\n");
    recvfrom(serversocket, request, sizeof(request), 0, (struct sockaddr *)&clientaddr, &len);
    printf("The request received is:\t%s", request);

    printf("\nPRESS ENTER TO SEND THE RESPONSE.\n");

    fgets(request, 2, stdin);

    printf("\nSending the 220:SERVICE READY COMMAND.\n");
    strcpy(request, "220:SERVICE READY.");
    sendto(serversocket, request, sizeof(request), 0, (struct sockaddr *)&clientaddr, len);
    printf("Waiting for the next request.");
    recvfrom(serversocket, request, sizeof(request), 0, (struct sockaddr *)&clientaddr, &len);
    cls();

    printf("\nThe client has send:\t%s\n", request);
    printf("\nPRESS ENTER TO SEND THE RESPONSE.\n");

    fgets(request, 2, stdin);

printf("\nSending the POSITIVE COMPLETION REPLY:250 REQUEST COMMAND

 

 

 

COMPLETED.\n");

strcpy(request,"250:REQUEST COMMAND COMPLETED.");

sendto(serversocket,request,sizeof(request),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr)); printf("\nWaiting for the next request.\n");

recvfrom(serversocket,request,sizeof(request),0,(struct sockaddr*)&clientaddr,&len);

cls();

printf("\nThe client has send:\t%s\n",request); strcpy(from,request);

printf("\nPRESS ENTER TO SEND THE RESPONSE.\n");

fgets(request,2,stdin);

printf("\nSending the POSITIVE COMPLETION REPLY:250\n"); strcpy(request,"250:REQUEST COMMAND COMPLETED.");

sendto(serversocket,request,sizeof(request),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));

printf("\nWaiting for the next request.\n"); recvfrom(serversocket,request,sizeof(request),0,(struct sockaddr*)&clientaddr,&len);

cls();

printf("\nThe client has send:\t%s\n",request); strcpy(to,request);

printf("\nPRESS ENTER TO SEND THE RESPONSE.\n");

fgets(request,2,stdin);

printf("\nSending the POSITIVE COMPLETION REPLY:250\n"); strcpy(request,"250:REQUEST COMMAND COMPLETED.");

sendto(serversocket,request,sizeof(request),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr)); printf("\nWaiting for the next request.\n"); recvfrom(serversocket,request,sizeof(request),0,(struct sockaddr*)&clientaddr,&len);

cls();

printf("\nThe client has send:\t%s\n",request); printf("\nPRESS ENTER TO SEND THE RESPONSE.\n");

fgets(request,2,stdin);

printf("\nSending the 354:START MAIL INPUT.\n"); strcpy(request,"354:START MAIL INPUT.");

sendto(serversocket,request,sizeof(request),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr)); printf("\nWaiting for the mail\n");

recvfrom(serversocket,request,sizeof(request),0,(struct sockaddr*)&clientaddr,&len); strcpy(mail,request);

 

 

 

cls();

printf("\n\n\n\t\t\tTHE DETAILS INCLUDE:\n"); printf("\n\n\t\t%s",from);

printf("\n\n\t\t%s",to); printf("\n\n\t\tMAIL:%s",mail);

printf("\n\n\nSEARCHING FOR THE RECIPIENT AND MESSAGE PASSED FOR ENDING.");

printf("\nPRESS ENTER TO SEND THE RESPONSE.\n");

fgets(request,2,stdin);

printf("\nSending the POSITIVE COMPLETION REPLY:250\n"); strcpy(request,"250 REQUEST COMMAND COMPLETED.");

sendto(serversocket,request,sizeof(request),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr)); printf("\nWaiting for the next request.\n"); recvfrom(serversocket,request,sizeof(request),0,(struct sockaddr*)&clientaddr,&len);

cls();

printf("\nThe client has send:\t%s\n",request); printf("\nPRESS ENTER TO SEND THE RESPONSE.\n");

fgets(request,2,stdin);

printf("\nSending the 221:SERVICE CLOSING.\n"); strcpy(request,"221:SERVICE CLOSING.");

sendto(serversocket,request,sizeof(request),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr)); cls();

printf("\n\n\nSERVER SHUTTING DOWN.\n");
}