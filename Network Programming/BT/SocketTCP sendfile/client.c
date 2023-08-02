#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>

#define SERVER_ADDR "127.0.0.1"
#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./client IPAddress PortNumber\n");
        exit(1);
    }
    char *ip = argv[1];
    int port = atoi(argv[2]);

	int client_sock;
	char buff[BUFF_SIZE] = {};
	struct sockaddr_in server_addr; /* server's address information */
	int msg_len, bytes_sent, bytes_received;
	
	//Step 1: Construct socket
	client_sock = socket(AF_INET,SOCK_STREAM,0);
	
	//Step 2: Specify server address
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = inet_addr(ip);
	
	//Step 3: Request to connect server
	if(connect(client_sock, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) < 0){
		printf("\nError!Can not connect to sever! Client exit imediately!\n ");
		return 0;
	}
		
    int option = 0;
	//Step 4: Communicate with server			
	while(1){
        option = 0;
        printf("MENU\n");
        printf("---------------------------\n");
        printf("1. Gui xau bat ky\n");
        printf("2. Gui noi dung mot file\n");
        char input[10] = {};
        fgets(input, sizeof(input), stdin); // Read string input from user
        option = atoi(input); // Convert string to integer		
        while(option == 1){
            printf("> ");
            memset(buff, '\0', (strlen(buff) + 1));
            fgets(buff, BUFF_SIZE, stdin);
            msg_len = strlen(buff);
            if (msg_len == 0 || msg_len == 1) {
                printf("\n");
                break;
            }
            
            bytes_sent = send(client_sock, buff, msg_len, 0);
            if(bytes_sent <= 0){
                printf("\nConnection closed!\n");
                break;
            }
            
            char digits[BUFF_SIZE] = {0}, letters[BUFF_SIZE] = {0};
            int i = 0, j = 0, k = 0;
            int error = 0;
            for (i = 0; i < msg_len - 1; i++) {
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
                memset(buff, '\0', (strlen(buff) + 1));
                bytes_received = recv(client_sock, buff, BUFF_SIZE-1, 0);
                if(bytes_received <= 0){
                    printf("\nError!Cannot receive data from sever!\n");
                    break;
                }
                
                buff[bytes_received] = '\0';
                printf("%s\n", buff);
                memset(buff, '\0', (strlen(buff) + 1));
                continue;
            }
            memset(buff, '\0', (strlen(buff) + 1));
            bytes_received = recv(client_sock, buff, BUFF_SIZE-1, 0);
            if(bytes_received <= 0){
                printf("\nError!Cannot receive data from sever!\n");
                break;
            } else {
                // printf("Received: %d\n", bytes_received);
            }
            
            buff[bytes_received] = '\0';
            printf("%s\n", buff);
            
            int has_digit = 0;
            int has_letter = 0;
            for (int i = 0; i < bytes_received; i++) {
                if (isdigit(buff[i])) {
                    has_digit = 1;
                }
                else if (isalpha(buff[i])) {
                    has_letter = 1;
                }
            }
            if(has_digit && has_letter) { j = 0; }

            if(j == 0 || k == 0){
                
            } else {
                memset(buff, '\0', (strlen(buff) + 1));
                bytes_received = recv(client_sock, buff, BUFF_SIZE-1, 0);
                if(bytes_received <= 0){
                    printf("\nError!Cannot receive data from sever!\n");
                    break;
                } else {
                    // printf("Received: %d\n", bytes_received);
                }
                buff[bytes_received] = '\0';
                printf("%s\n", buff);
                memset(buff, '\0', (strlen(buff) + 1));
            }
        } 
        if(option == 2){
            printf("> ");
            memset(buff,'\0',(strlen(buff)+1));
            fgets(buff, BUFF_SIZE, stdin);		
            msg_len = strlen(buff);
            if (msg_len == 0) break;

            // đọc file và gửi nội dung qua
            FILE *file;
            char buffer[BUFF_SIZE - 6] = {};
            size_t n;
            buff[strlen(buff) - 1] = '\0';
            // printf("Buff: %s\n", buff);
            file = fopen(buff, "r");
            if (file == NULL) {
                perror("Error opening file");
                continue;
            }
            while ((n = fread(buffer, sizeof(char), BUFF_SIZE - 7, file)) > 0) {
                // printf("\n!!!!!!!!!!!!!!!!!!!okokokok!!!!!!!!\n\n\n\n");
                char prefix[7] = "!file:";
                char result[BUFF_SIZE] = {};
                memmove(result, prefix, strlen(prefix) + 1);
                memmove(result + strlen(prefix), buffer, strlen(buffer) + 1);
                result[strlen(result)] = '\0';
                // printf("Send data: %s\n", result);

                bytes_sent = send(client_sock, result, strlen(result), 0);
                if(bytes_sent <= 0){
                    printf("\nConnection closed!\n");
                    break;
                }
                bytes_received = recv(client_sock, buff, BUFF_SIZE - 1, 0);
                if(bytes_received <= 0){
                    printf("\nError!Cannot receive data from sever!\n");
                    break;
                }
                buff[bytes_received] = '\0';
                printf("%s", buff);
                memset(buff,'\0',(strlen(buff)+1));
                memset(buffer,'\0',(strlen(buffer)+1));
                memset(result,'\0',(strlen(result)+1));
            }
            printf("\n\n");
            memset(buff,'\0',(strlen(buff)+1));
            memset(buffer,'\0',(strlen(buffer)+1));
            fclose(file);
        }
	}
	
	//Step 4: Close socket
	close(client_sock);
	return 0;
}
