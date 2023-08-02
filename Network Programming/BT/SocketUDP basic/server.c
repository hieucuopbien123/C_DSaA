#include <stdio.h>  
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./server PortNumber\n");
        exit(1);
    }
    int port = atoi(argv[1]);

	int server_sock;
	char buff[BUFF_SIZE];
	int bytes_sent, bytes_received;
	struct sockaddr_in server; 
	struct sockaddr_in clientList[2]; 
	struct sockaddr_in client; 
	int sin_size;

	//Step 1: Construct a UDP socket
    if ((server_sock=socket(AF_INET, SOCK_DGRAM, 0)) == -1 ){
		perror("\nError: ");
		exit(0);
	}
	
	//Step 2: Bind address to socket
	server.sin_family = AF_INET;         
	server.sin_port = htons(port); 
	server.sin_addr.s_addr = INADDR_ANY; 
    bzero(&(server.sin_zero),8);

    if(bind(server_sock,(struct sockaddr*)&server,sizeof(struct sockaddr))==-1){
		perror("\nError: ");
		exit(0);
	}     

	//Step 3: Communicate with clients
    int index = 0;
	while(1){
        sin_size=sizeof(struct sockaddr_in);
        
        bytes_received = recvfrom(server_sock, buff, BUFF_SIZE-1, 0, (struct sockaddr *) &client, &sin_size);
		if (bytes_received < 0)
			perror("\nError: ");
		else{
			buff[bytes_received] = '\0';
			printf("[%s:%d]: %s", inet_ntoa(client.sin_addr), ntohs(client.sin_port), buff);
		}

        if(index == 0){
            clientList[0] = client;
            buff[0] = '1';
            buff[1] = '\0';
            bytes_sent = sendto(server_sock, buff, bytes_received, 0, (struct sockaddr *) &clientList[0], sin_size ); 
            if (bytes_sent < 0)
                perror("\nError: ");
            index = 1;
        } else if(index == 1){
            if(strcmp(inet_ntoa(clientList[0].sin_addr), inet_ntoa(client.sin_addr)) == 0 &&
                clientList[0].sin_port == client.sin_port)
            {
                continue;
            } 
            clientList[1] = client;

            buff[0] = '2';
            buff[1] = '\0';
            bytes_sent = sendto(server_sock, buff, bytes_received, 0, (struct sockaddr *) &clientList[1], sin_size ); 
            if (bytes_sent < 0)
                perror("\nError: ");
            index = 2;
        } else {
            if(strcmp(inet_ntoa(clientList[0].sin_addr), inet_ntoa(client.sin_addr)) == 0 &&
                clientList[0].sin_port == client.sin_port)
            {
                char digits[BUFF_SIZE] = {0}, letters[BUFF_SIZE] = {0};
                int i = 0, j = 0, k = 0;
                int error = 0;
                for (i = 0; i < bytes_received - 1; i++) {
                    if (isdigit(buff[i])) {
                        digits[j++] = buff[i];
                    } else if(isalpha(buff[i])) {
                        letters[k++] = buff[i];
                    } else {
                        error = 1;
                        break;
                    }
                }
                if(error == 1){
                    char str[] = "Error";
                    sendto(server_sock, str, strlen(str), 0, (struct sockaddr *) &(clientList[1]), sin_size);
                    continue;
                }
                digits[j] = '\0';
                letters[k] = '\0';

                // Send the digits back to the client
                if (j > 0 && sendto(server_sock, digits, strlen(digits), 0, (struct sockaddr *) &(clientList[1]), sin_size) < 0) {
                    perror("sendto failed");
                    close(server_sock);
                    return -1;
                }
                if (k > 0 && sendto(server_sock, letters, strlen(letters), 0, (struct sockaddr *) &(clientList[1]), sin_size) < 0) {
                    perror("sendto failed");
                    close(server_sock);
                    return -1;
                }
            } 
            else {
                perror("\nError: ");
            }
        }
	}
	
	close(server_sock);
	return 0;
}
