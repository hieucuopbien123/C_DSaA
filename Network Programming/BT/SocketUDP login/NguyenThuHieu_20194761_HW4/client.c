#include <stdio.h>   
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/select.h>
#include <termios.h>
#include <fcntl.h>
#include <ctype.h>

int checkNotAlphaNum(char arr[])
{
    int is_alnum = 1;

    // printf("x%dx", strlen(arr));
    for (int i = 0; arr[i] != '\0'; i++) {
        if (!isalnum(arr[i])) {
            // printf("Char: %c\n", arr[i]);
            // printf("Char: %d\n", arr[i]);
            // printf("R: %d\n", arr[i] == '\n');
            if(arr[i] == '\n') continue;
            // printf("Set isAlpnum\n");
            is_alnum = 0;
            break;
        }
    }
    // printf("isalnum: %d\n", is_alnum);
    if (is_alnum == 1) {
        // printf("isalnum: %d\n", is_alnum);
        return 0;
    } else {
        return 1;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./client IPAddress PortNumber\n");
        exit(1);
    }
    char *ip = argv[1];
    int port = atoi(argv[2]);

	//Step 1: Construct a UDP socket
	int client_sock;
	if ((client_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ){
		perror("\nError: Cannot create socket");
		exit(0);
	}

	//Step 2: Define the address of the server	
    struct sockaddr_in server_addr;
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = inet_addr(ip);
	
	// Step 3: Communicate with server
    char buff[1024];
    char buffer[1024];
	int bytes_sent;
    int sin_size = sizeof(struct sockaddr);
    memset(buff, '\0', (strlen(buff) + 1));
    memset(buffer, '\0', (strlen(buffer) + 1));

    // Setup non blocking IO
    fd_set rfds;
    struct timeval tv;
    int retval;

    // Setup non blocking socket
    int flags = fcntl(client_sock, F_GETFL, 0);
    fcntl(client_sock, F_SETFL, flags | O_NONBLOCK);

    char username[500] = {};
    char password[500] = {};
    memset(username, '\0', (strlen(username) + 1));
    memset(password, '\0', (strlen(password) + 1));

    while(1){
        FD_ZERO(&rfds);
        memset(buffer, '\0', (strlen(buffer) + 1));
        FD_SET(STDIN_FILENO, &rfds);
        FD_SET(client_sock, &rfds);
        tv.tv_sec = 1;
        tv.tv_usec = 0;

        int bytes_received = recv(client_sock, buff, sizeof(buff), 0);
        if (bytes_received > 0) {
            // data received, print it
            printf("%s\n", buff);
            // printf("Check: %d\n", strcmp(buff, "Account is blocked"));
            // printf("Check: %d\n", strcmp(buff, "Account is blocked\0"));
            if(strcmp(buff, "Not OK") == 0 || strcmp(buff, "Account not ready") == 0 || strcmp(buff, "Account is blocked") == 0 || strcmp(buff, "Account already used") == 0){
                // printf("reset pass\n");
                memset(password, '\0', (strlen(password) + 1));
                memset(username, '\0', (strlen(username) + 1));
            }
            memset(buff, '\0', (strlen(buff) + 1));
        }
        else if (bytes_received == 0) {
            // connection closed
            break;
        }
        else {
            // no data received, do nothing and keep checking
        }


        /* Check if there is data to read from stdin. */
        retval = select(1, &rfds, NULL, NULL, &tv);
        if (retval == -1) {
            perror("select()");
        } else if (retval) {
            /* There is data to read from stdin. */
            char buffer[1024];
            // ssize_t num_read = read(0, buffer, sizeof(buffer) - 1);
            int num_read = 1;
            fgets(buffer, 1023, stdin);
            if (num_read == -1) {
                perror("read()");
            } else {
                /* Use the data read from stdin. */
                // printf("Data to send: %s", buffer);
                if(strlen(buffer) == 0) {
                    continue;
                }
                if(buffer[0] == 'b' && buffer[1] == 'y' && buffer[2] == 'e'){
                    if(strlen(username) == 0) {
                        printf("Goodbye\n");
                    } else {
                        printf("Goodbye %s", username);
                    }
                    exit(1);
                    return 1;
                }
                if(checkNotAlphaNum(buffer) == 1)
                {
                    printf("Error\n");
                    memset(buffer, '\0', (strlen(buffer) + 1));
                    continue;
                }
                if (username[0] == '\0') {
                    strcpy(username, buffer);
                    printf("Input password\n");
                    memset(buffer, '\0', (strlen(buffer) + 1));
                    // continue;
                } else if(password[0] == '\0'){
                    strcpy(password, buffer);
                    memset(buffer, '\0', (strlen(buffer) + 1));
                    int num = 1;

                    sprintf(buffer, "%d \"%s\" \"%s\"", num, username, password);
                    bytes_sent = sendto(client_sock, buffer, strlen(buffer), 0, (struct sockaddr *) &server_addr, sin_size);
                    if(bytes_sent < 0){
                        perror("Error: Cannot send data");
                        close(client_sock);
                        return 0;
                    }
                    memset(buffer, '\0', (strlen(buffer) + 1));
                    // continue;
                } else {
                    strcpy(password, buffer);
                    memset(buffer, '\0', (strlen(buffer) + 1));
                    int num = 0;

                    sprintf(buffer, "%d \"%s\" \"%s\"", num, username, password);
                    bytes_sent = sendto(client_sock, buffer, strlen(buffer), 0, (struct sockaddr *) &server_addr, sin_size);
                    if(bytes_sent < 0){
                        perror("Error: Cannot send data");
                        close(client_sock);
                        return 0;
                    }
                    memset(buffer, '\0', (strlen(buffer) + 1));
                }

                // printf("Print username: %s", username);
                // printf("Print password: %s", password);

                // bytes_sent = sendto(client_sock, buffer, strlen(buffer), 0, (struct sockaddr *) &server_addr, sin_size);
                // if(bytes_sent < 0){
                //     perror("Error: Cannot send data");
                //     close(client_sock);
                //     return 0;
                // }
                // memset(buffer, '\0', (strlen(buffer) + 1));
            }
        } else {
            /* There is no data to read from stdin. */
            continue;
        }
    }

	close(client_sock);
	return 0;
}
