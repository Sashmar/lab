#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#define SERV_TCP_PORT 5035
#define MAX 60
char buff[4096], t;
int i, j, item;
FILE *f1;
int main(int afg, char *argv)
{
    int sockfd, newsockfd, clength;
    char t[MAX], str[MAX];
    struct sockaddr_in serv_addr, cli_addr;
    strcpy(t, "exit");
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(SERV_TCP_PORT);
    printf("\n binded");
    bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(sockfd, 5);
    clength = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clength);
    close(sockfd);
    read(newsockfd, &str, MAX);
    printf("\nclient message \n,file name:%s\n", str);
    f1 = fopen(str, "r");
    while (fgets(buff, 4096, f1) != NULL)
    {
        write(newsockfd, buff, MAX);
        printf("\n");
    }
    fclose(f1);
    printf("\n file transferred");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#define SERV_TCP_PORT 5035
#define MAX 60
char buff[4096], t;
int i, j, item;
FILE *f1;
int main(int afg, char *argv)
{
    int sockfd, newsockfd, clength, n;
    struct hostent *server;
    char t[MAX], str[MAX], send[MAX], recvline[MAX], s[MAX], name[MAX];
    struct sockaddr_in serv_addr, cli_addr;
    strcpy(t, "exit");
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(SERV_TCP_PORT);
    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    printf("\n enter source file name:");
    scanf("%s", send);
    write(sockfd, send, MAX);
    while ((n = read(sockfd, recvline, MAX)) != 0)
    {
        printf("%s", recvline);
    }
    close(sockfd);
    return 0;
}
