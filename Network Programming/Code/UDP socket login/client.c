#include <stdio.h>   
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./client IPAddress PortNumber\n");
        exit(1);
    }
    char *ip = argv[1];
    int port = atoi(argv[2]);

	int client_sock;
	char buff[BUFF_SIZE];
	struct sockaddr_in server_addr;
	int bytes_sent,bytes_received, sin_size;
	
	//Step 1: Construct a UDP socket
	if ((client_sock=socket(AF_INET, SOCK_DGRAM, 0)) < 0 ){
		perror("\nError: ");
		exit(0);
	}

	//Step 2: Define the address of the server
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = inet_addr(ip);
	
	//Step 3: Communicate with server
    memset(buff,'\0',(strlen(buff)+1));
    sin_size = sizeof(struct sockaddr);
    strcpy(buff, "Welcome\n");
    bytes_sent = sendto(client_sock, buff, strlen(buff), 0, (struct sockaddr *) &server_addr, sin_size);
    if(bytes_sent < 0){
        perror("Error: ");
        close(client_sock);
        return 0;
    }
    bytes_received = recvfrom(client_sock, buff, BUFF_SIZE - 1, 0, (struct sockaddr *) &server_addr, &sin_size);
    if(bytes_received < 0){
        perror("Error: ");
        close(client_sock);
        return 0;
    }
    buff[bytes_received] = '\0';
    int role = 0;
    if(buff[0] == '1'){
        role = 1;
    } else {
        role = 2;
    }
    if(role == 1){
        while(1){
            printf("> ");
            memset(buff,'\0',(strlen(buff)+1));
            if(fgets(buff, BUFF_SIZE, stdin) != NULL){
                sin_size = sizeof(struct sockaddr);
                
                bytes_sent = sendto(client_sock, buff, strlen(buff), 0, (struct sockaddr *) &server_addr, sin_size);
                if(bytes_sent < 0){
                    perror("Error: ");
                    close(client_sock);
                    return 0;
                }
            }
        }
    } else {
        while(1){
            int serverLen = sizeof(server_addr);
            int recvLen = recvfrom(client_sock, buff, BUFF_SIZE, 0, (struct sockaddr *)&server_addr, &serverLen);

            if (recvLen < 0) {
                perror("Error");
                exit(1);
            }

            buff[recvLen] = '\0';

            printf("%s\n", buff);
        }
    }

	close(client_sock);
	return 0;
}
