#include <stdio.h>          /* These are the usual header files */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>

#define BACKLOG 2   /* Number of allowed connections */
#define BUFF_SIZE 8000

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./server PortNumber\n");
        exit(1);
    }
    int port = atoi(argv[1]);
	int listen_sock, conn_sock; /* file descriptors */
	char recv_data[BUFF_SIZE] = {};
	int bytes_sent, bytes_received;
	struct sockaddr_in server; /* server's address information */
	struct sockaddr_in client; /* client's address information */
	int sin_size;
	
	//Step 1: Construct a TCP socket to listen connection request
	if ((listen_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){  /* calls socket() */
		perror("\nError: ");
		return 0;
	}
	
	//Step 2: Bind address to socket
	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;         
	server.sin_port = htons(port);   /* Remember htons() from "Conversions" section? =) */
	server.sin_addr.s_addr = htonl(INADDR_ANY);  /* INADDR_ANY puts your IP address automatically */   
	if(bind(listen_sock, (struct sockaddr*)&server, sizeof(server))==-1){ /* calls bind() */
		perror("\nError: ");
		return 0;
	}     
	
	//Step 3: Listen request from client
	if(listen(listen_sock, BACKLOG) == -1){  /* calls listen() */
		perror("\nError: ");
		return 0;
	}
	
	//Step 4: Communicate with client
	while(1){
		//accept request
		sin_size = sizeof(struct sockaddr_in);
		if ((conn_sock = accept(listen_sock,( struct sockaddr *)&client, &sin_size)) == -1) 
			perror("\nError: ");
		printf("\nYou got a connection from %s\n", inet_ntoa(client.sin_addr) ); /* prints client's IP */
		
		//start conversation
		while(1){
			//receives message from client
			memset(recv_data,'\0',(strlen(recv_data)+1));
			bytes_received = recv(conn_sock, recv_data, BUFF_SIZE-1, 0); //blocking
			if (bytes_received <= 0){
				printf("\nConnection closed");
				break;
			}
			else{
				recv_data[bytes_received] = '\0';
				printf("\nReceive: %s\n", recv_data);
			}
			if(bytes_received > 5){
				if(recv_data[0] == '!' && recv_data[1] == 'f' && recv_data[2] == 'i' && recv_data[3] == 'l' && recv_data[4] =='e' && recv_data[5] == ':') {
    				memmove(recv_data, recv_data + 6, strlen(recv_data) - 5);
					bytes_sent = send(conn_sock, recv_data, bytes_received, 0); /* send to the client welcome message */
					memset(recv_data,'\0',(strlen(recv_data)+1));
					if (bytes_sent <= 0){
						printf("\nConnection closed");
						break;
					}
					continue;
				}
			}
			
            char digits[BUFF_SIZE] = {0}, letters[BUFF_SIZE] = {0};
            int i = 0, j = 0, k = 0;
            int error = 0;
            for (i = 0; i < bytes_received - 1; i++) {
                if (isdigit(recv_data[i])) {
                    digits[j++] = recv_data[i];
                } else if(isalpha(recv_data[i])) {
                    letters[k++] = recv_data[i];
                } else {
                    error = 1;
                    break;
                }
            }
			memset(recv_data,'\0',(strlen(recv_data)+1));
            if(error == 1){
                char str[] = "Error";
                send(conn_sock, str, strlen(str), 0);
                continue;
            }
            digits[j] = '\0';
            letters[k] = '\0';
			//echo to client
			if(j > 0){
				printf("%s\n", digits); // chả hiểu sao xóa dòng này gây lỗi
				// **** Phải có linefeed \n ở mọi message để tránh các lỗi ở standard input output trong C
				bytes_sent = send(conn_sock, digits, strlen(digits), 0); /* send to the client welcome message */
				if (bytes_sent <= 0){
					printf("\nConnection closed");
					break;
				} else {
					printf("Sent: %d\n", bytes_sent);
				}
			}
			if(k > 0){
				printf("%s\n", letters);
				bytes_sent = send(conn_sock, letters, strlen(letters), 0); /* send to the client welcome message */
				if (bytes_sent <= 0){
					printf("\nConnection closed");
					break;
				} else {
					printf("Sent: %d\n", bytes_sent);
				}
			}
		}
		close(conn_sock);	
	}
	
	close(listen_sock);
	return 0;
}
