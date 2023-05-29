#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    int isDomain = 0;
    for(int i = 0; i < strlen(argv[1]); i++){
        if(isalpha(argv[1][i])){
            isDomain = 1;
            break;
        }
    }
    if(argc > 2){
        printf("Not found information\n");
        return 1;
    }
    if(isDomain == 1){
        const char *hostname = argv[1];
        struct addrinfo hints, *res;
        char ipstr[INET6_ADDRSTRLEN];
        memset(&hints, 0, sizeof hints);
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_CANONNAME | AI_ALL;
        int status = getaddrinfo(hostname, NULL, &hints, &res);
        if (status != 0) {
            printf("Not found information\n");
            exit(EXIT_FAILURE);
        }
        char ips[50][50] = {};
        int index = 0;
        int isOffical = 1;
        for (struct addrinfo *p = res; p != NULL; p = p->ai_next) {
            void *addr;
            if (p->ai_family == AF_INET) { 
                struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
                addr = &(ipv4->sin_addr);
                inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
                if(isOffical == 1){
                    isOffical = 0;
                    printf("Official IP: %s\n", ipstr);
                } else {
                    strcpy(ips[index++], ipstr);
                }
            }
        }
        if(index > 0){
            printf("Alias IP:\n");
            for(int i = 0; i < index; i++){
                printf("- %s\n", ips[i]);
            }
        } else {
            printf("Found 0 alias IP\n");
        }
        freeaddrinfo(res); // free the linked list
    } else {
        struct in_addr addr;
        struct hostent *host;
        addr.s_addr = inet_addr(argv[1]);
        host = gethostbyaddr(&addr, sizeof(addr), AF_INET);
        if (host == NULL) {
            printf("Not found information\n");
            return 1;
        }
        printf("Official name: %s\n", host->h_name);
        if(host->h_aliases[0] != NULL){
            printf("Alias name:\n");
            for (int i = 0; host->h_aliases[i] != NULL; i++) {
                printf("- %s\n", host->h_aliases[i]);
            }
        } else {
            printf("Found 0 alias name\n");
        }
    }
    return 0;
}
