#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <arpa/inet.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./server PortNumber\n");
        exit(1);
    }
    int port = atoi(argv[1]);
    int times[100];
    int isActive[100];

    // Create
    int server_sock;
    if ((server_sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1 ){
		perror("\nError: cannot create socket");
		exit(0);
	}

    // Bind
    struct sockaddr_in server; 
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server.sin_zero),8);
    if(bind(server_sock, (const struct sockaddr*)&server, sizeof(struct sockaddr)) < 0 )
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Connect with client
    int bytes_sent, bytes_received;
	struct sockaddr_in client;
	// struct sockaddr_in clients[100];
    // int cnum = 0; 
    // int userActive[100] = {};
    socklen_t sin_size = sizeof(struct sockaddr_in);
	char buff[1024];

    FILE *fp;
    char user[100][100];
    int i = 0;
    fp = fopen("./account.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    while (fgets(user[i], 100, fp) != NULL) {
        i++;
    }
    fclose(fp);
    char username[100][100] = {};
    char password[100][100] = {};
    char state[100][2] = {};

    for(int j = 0; j < i; j++) {
        sscanf(user[j], "%s %s %s", username[j], password[j], state[j]);
        times[j] = 0;
        isActive[j] = 0;
    }
    // for (int j = 0; j < i; j++) {
    //     char *token;
    //     int x = 0;

    //     token = strtok(user[j], " ");
    //     while (token != NULL && x < 3) {
    //         if (x == 0) {
    //             strncpy(username[j], token, sizeof(username[j]));
    //             username[j][sizeof(username[j]) - 1] = '\0';
    //         }
    //         else if (x == 1) {
    //             strncpy(password[j], token, sizeof(password[j]));
    //             password[j][sizeof(password[j]) - 1] = '\0';
    //         }
    //         else if (x == 2) {
    //             strncpy(state[j], token, sizeof(state[j]));
    //             state[j][sizeof(state[j]) - 1] = '\0';
    //         }
    //         token = strtok(NULL, " ");
    //         x++;
    //     }
    // }
    // for (int j = 0; j < i; j++) {
    //     printf("%s\n", username[j]);
    // }
    // for (int j = 0; j < i; j++) {
    //     printf("%s\n", password[j]);
    // }
    // for (int j = 0; j < i; j++) {
    //     printf("%s\n", state[j]);
    // }

    while(1){
        bytes_received = recvfrom(server_sock, buff, 1024 - 1, 0, (struct sockaddr*)&client, &sin_size);
		if (bytes_received < 0)
			perror("\nError: ");
		else{
			buff[bytes_received] = '\0';
			// printf("[%s:%d]: %s\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port), buff);
		}
		
        // Handle buffer
        if(buff[0] == 'b' && buff[1] == 'y' && buff[2] == 'e'){
            continue;
        }

        int extracted_num;
        char extracted_arr1[100];
        char extracted_arr2[100];
        sscanf(buff, "%d \"%[^\"]\" \"%[^\"]\"", &extracted_num, extracted_arr1, extracted_arr2);
        extracted_arr1[strlen(extracted_arr1) - 1] = '\0';
        extracted_arr2[strlen(extracted_arr2) - 1] = '\0';
        // printf("%d %s %s \n", extracted_num, extracted_arr1, extracted_arr2);
        // printf("Size: %lu %lu\n", strlen(extracted_arr1), strlen(extracted_arr2));
        // printf("int: %d\n", extracted_num == 0);

        if(extracted_num == 1){
            int pos = -1;
            // printf("Existx\n");
            for(int j = 0; j < i; j++){
                if(strcmp(username[j], extracted_arr1) == 0) {
                    if(strcmp(password[j], extracted_arr2) == 0) {
                        // printf("Exist\n");
                        pos = j;
                        break;
                    }
                }
            }
            // printf("Size3: %lu %lu\n", strlen(extracted_arr1), strlen(extracted_arr2));
            if(pos == -1){
                // printf("Size2: %lu %lu\n", strlen(extracted_arr1), strlen(extracted_arr2));

                for(int j = 0; j < i; j++){
                    // printf("1: %s\n", username[j]);
                    // printf("2: %s\n", extracted_arr1);
                    if(strcmp(username[j], extracted_arr1) == 0) {
                        // printf("Beta: %d\n", j);
                        pos = j;
                        break;
                    }
                }
                times[pos]++;
                // printf("pos: %d\n", times[pos]);
                if(times[pos] >= 3){
                    FILE *fp;
                    char *line = NULL;
                    size_t len = 0;
                    ssize_t read;
                    int line_num = pos + 1;  // Update the third line
                    // printf("Beta: %d\n", pos);

                    // Open the file for both reading and writing
                    fp = fopen("./account.txt", "r+");
                    if (fp == NULL) {
                        printf("Error opening file\n");
                        exit(EXIT_FAILURE);
                    }

                    // printf("Beta3: %d\n", pos);
                    int curr_line = 1;
                    while ((read = getline(&line, &len, fp)) != -1) {
                        if (curr_line == line_num) {
                            // Move the file pointer back to the beginning of the current line
                            fseek(fp, -read, SEEK_CUR);

                            // Modify the contents of the current line
                            char new_line[300] = {};
                            char separator[] = " ";
                            char separator2[] = "\n";
                            char newState[] = "0";

                            strcpy(new_line, username[pos]);
                            strcat(new_line, separator);
                            strcat(new_line, password[pos]);
                            strcat(new_line, separator);
                            strcat(new_line, newState);
                            strcat(new_line, separator2);

                            // printf("%s ___\n", username[pos]);
                            // printf("%s ___\n", password[pos]);
                            // printf("%s ___\n", state[pos]);
                            // printf("%s ___\n", new_line);
                            fputs(new_line, fp);

                            break;
                        }
                        curr_line++;
                    }

                    // Close the file and free memory
                    fclose(fp);
                    if (line) {
                        free(line);
                    }

                    memset(buff, '\0', (strlen(buff) + 1));
                    char arr1[] = "Account is blocked\0";
                    strcpy(buff, arr1);
                    // printf("%s\n", buff);
                    // printf("%d\n", strlen(buff));
                    // printf("%d\n", bytes_received);
                    bytes_sent = sendto(server_sock, buff, strlen(buff), 0, (struct sockaddr *) &client, sin_size );
                    if (bytes_sent < 0) perror("\nError: ");
                    // printf("B: %d\n", bytes_sent);
                    memset(buff, '\0', (strlen(buff) + 1));
                    continue;
                } else {
                    memset(buff, '\0', (strlen(buff) + 1));
                    char arr1[] = "Not OK\0";
                    strcpy(buff, arr1);
                    // printf("%s\n", buff);
                    // printf("%d\n", strlen(buff));
                    // printf("%d\n", bytes_received);
                    bytes_sent = sendto(server_sock, buff, strlen(buff), 0, (struct sockaddr *) &client, sin_size );
                    if (bytes_sent < 0) perror("\nError: ");
                    // printf("B: %d\n", bytes_sent);
                    memset(buff, '\0', (strlen(buff) + 1));
                    continue;
                }
            } else {
                // printf("state: %s\n", state[pos]);
                if(strcmp(state[pos], "0") == 0){
                    // printf("Size21: %lu %lu\n", strlen(extracted_arr1), strlen(extracted_arr2));
                    memset(buff, '\0', (strlen(buff) + 1));
                    char arr1[] = "Account not ready\0";
                    strcpy(buff, arr1);
                    // printf("%s\n", buff);
                    // printf("%d\n", strlen(buff));
                    // printf("%d\n", bytes_received);
                    bytes_sent = sendto(server_sock, buff, strlen(buff), 0, (struct sockaddr *) &client, sin_size );
                    if (bytes_sent < 0) perror("\nError: ");
                    // printf("Beta: %d\n", bytes_sent);
                    memset(buff, '\0', (strlen(buff) + 1));
                    continue;
                } else {
                    if(isActive[pos] == 0)
                    {
                        times[pos] = 0;
                        // printf("Size22: %lu %lu\n", strlen(extracted_arr1), strlen(extracted_arr2));
                        memset(buff, '\0', (strlen(buff) + 1));
                        char arr1[] = "OK\0";
                        strcpy(buff, arr1);
                        // printf("%s\n", buff);
                        // printf("%d\n", strlen(buff));
                        // printf("%d\n", bytes_received);
                        bytes_sent = sendto(server_sock, buff, strlen(buff), 0, (struct sockaddr *) &client, sin_size );
                        if (bytes_sent < 0) perror("\nError: ");
                        // printf("Beta: %d\n", bytes_sent);
                        memset(buff, '\0', (strlen(buff) + 1));
                        continue;
                        isActive[pos] = 1;
                    } else {
                        times[pos] = 0;
                        // printf("Size22: %lu %lu\n", strlen(extracted_arr1), strlen(extracted_arr2));
                        memset(buff, '\0', (strlen(buff) + 1));
                        char arr1[] = "Account already used\0";
                        strcpy(buff, arr1);
                        // printf("%s\n", buff);
                        // printf("%d\n", strlen(buff));
                        // printf("%d\n", bytes_received);
                        bytes_sent = sendto(server_sock, buff, strlen(buff), 0, (struct sockaddr *) &client, sin_size );
                        if (bytes_sent < 0) perror("\nError: ");
                        // printf("Beta: %d\n", bytes_sent);
                        memset(buff, '\0', (strlen(buff) + 1));
                        continue;
                    }
                }
            }
        } else {
            int pos = -1;
            // printf("x: %d\n", extracted_num);
            // printf("x: %d\n", i);
            for(int j = 0; j < i; j++){
                // printf("1: %s\n", username[j]);
                // printf("2: %s\n", extracted_arr1);
                if(strcmp(username[j], extracted_arr1) == 0) {
                    // printf("Beta: %d\n", j);
                    pos = j;
                    break;
                }
            }
            if(pos != -1){
                FILE *fp = fopen("./account.txt", "w");
                char dataToWrite[10000] = {};
                char separator[] = " ";
                char separator2[] = "\n";
                printf("%d\n", i);
                for(int j = 0; j < i; j++){
                    if(j == pos){
                        strcpy(password[j], extracted_arr2);
                    }
                    strcat(dataToWrite, username[j]);
                    strcat(dataToWrite, separator);
                    strcat(dataToWrite, password[j]);
                    strcat(dataToWrite, separator);
                    strcat(dataToWrite, state[j]);
                    strcat(dataToWrite, separator2);
                }
                if (fp == NULL) {
                    printf("Error opening file\n");
                    return 1;
                }
                // fprintf(fp, dataToWrite);
                // fwrite(dataToWrite, sizeof(char), sizeof(dataToWrite), fp);
                fputs(dataToWrite, fp);
                fclose(fp);
                // if(strlen(extracted_arr2) > strlen(password[pos])){
                //     printf("Close\n");
                //     FILE *fp1, *fp2;
                //     char line[100];
                //     char newLine[300] = {};
                //     char separator[] = " ";

                //     strcpy(newLine, username[pos]);
                //     strcat(newLine, separator);
                //     strcat(newLine, extracted_arr2);
                //     strcat(newLine, separator);
                //     strcat(newLine, state[pos]);

                //     strcpy(password[pos], extracted_arr2);

                //     int lineNum = pos + 1, count = 0;

                //     // open input file in read mode
                //     fp1 = fopen("./account.txt", "r");
                //     if (fp1 == NULL) {
                //         printf("Cannot open file %s\n", "path/to/input/file.txt");
                //         exit(EXIT_FAILURE);
                //     }

                //     // open temporary file in write mode
                //     fp2 = fopen("./input.txt", "w");
                //     if (fp2 == NULL) {
                //         printf("Cannot create file %s\n", "path/to/temp/file.txt");
                //         exit(EXIT_FAILURE);
                //     }

                //     // get line number and new line from user

                //     // copy lines from input file to temporary file
                //     while (fgets(line, sizeof(line), fp1)) {
                //         count++;

                //         // replace line if line number matches
                //         if (count == lineNum) {
                //             fputs(newLine, fp2);
                //             if (strlen(newLine) > strlen(line)) {
                //                 fputs("\n", fp2);
                //             }
                //         } else {
                //             fputs(line, fp2);
                //         }
                //     }

                //     // close files
                //     fclose(fp1);
                //     fclose(fp2);

                //     // delete input file
                //     remove("./account.txt");

                //     // rename temporary file to input file
                //     rename("./input.txt", "./account.txt");
                // } else {
                //     //!!!!!!
                //     FILE *fp;
                //     char *line = NULL;
                //     size_t len = 0;
                //     ssize_t read;
                //     int line_num = pos + 1;  // Update the third line
                //     printf("Beta: %d\n", pos);

                //     // Open the file for both reading and writing
                //     fp = fopen("./account.txt", "r+");
                //     if (fp == NULL) {
                //         printf("Error opening file\n");
                //         exit(EXIT_FAILURE);
                //     }

                //     // printf("Beta3: %d\n", pos);
                //     int curr_line = 1;
                //     while ((read = getline(&line, &len, fp)) != -1) {
                //         if (curr_line == line_num) {
                //             // Move the file pointer back to the beginning of the current line
                //             fseek(fp, -read, SEEK_CUR);

                //             // Modify the contents of the current line
                //             char new_line[300] = {};
                //             char separator[] = " ";
                //             char separator2[] = "\n";

                //             strcpy(new_line, username[pos]);
                //             strcat(new_line, separator);
                //             strcat(new_line, extracted_arr2);
                //             strcat(new_line, separator);
                //             strcat(new_line, state[pos]);
                //             strcat(new_line, separator2);

                //             strcpy(password[pos], extracted_arr2);

                //             // printf("%s ___\n", username[pos]);
                //             // printf("%s ___\n", extracted_arr2);
                //             // printf("%s ___\n", state[pos]);
                //             // printf("%s ___\n", new_line);
                //             fputs(new_line, fp);

                //             break;
                //         }
                //         curr_line++;
                //     }

                //     // Close the file and free memory
                //     fclose(fp);
                //     if (line) {
                //         free(line);
                //     }
                //     //!!!!!!!!
                // }


                char digits[1024] = {0}, letters[1024] = {0};
                int y = 0, j = 0, k = 0;
                int error = 0;
                for (y = 0; y < strlen(extracted_arr2); y++) {
                    if (isdigit(extracted_arr2[y])) {
                        digits[j++] = extracted_arr2[y];
                    } else if(isalpha(extracted_arr2[y])) {
                        letters[k++] = extracted_arr2[y];
                    } else {
                        error = 1;
                        break;
                    }
                }
                if(error == 1){
                    char str[] = "Error";
                    sendto(server_sock, str, strlen(str), 0, (struct sockaddr *) &(client), sin_size);
                    continue;
                }
                digits[j] = '\0';
                letters[k] = '\0';

                // Send the digits back to the client
                if (j > 0 && sendto(server_sock, digits, strlen(digits), 0, (struct sockaddr *) &(client), sin_size) < 0) {
                    perror("sendto failed");
                    close(server_sock);
                    return -1;
                }
                if (k > 0 && sendto(server_sock, letters, strlen(letters), 0, (struct sockaddr *) &(client), sin_size) < 0) {
                    perror("sendto failed");
                    close(server_sock);
                    return -1;
                }

                // memset(buff, '\0', (strlen(buff) + 1));
                // char arr1[] = "OK\n";
                // strcpy(buff, arr1);
                // printf("%s\n", buff);
                // printf("%d\n", strlen(buff));
                // printf("%d\n", bytes_received);
                // bytes_sent = sendto(server_sock, buff, strlen(buff), 0, (struct sockaddr *) &client, sin_size );
                // if (bytes_sent < 0) perror("\nError: ");
                // printf("Beta: %d\n", bytes_sent);
                // memset(buff, '\0', (strlen(buff) + 1));
                // continue;
            }
        }

        // printf("Size1: %lu %lu\n", strlen(extracted_arr1), strlen(extracted_arr2));
		// bytes_sent = sendto(server_sock, buff, bytes_received, 0, (struct sockaddr *) &client, sin_size );
		// if (bytes_sent < 0) perror("\nError: ");	

        

        memset(buff, '\0', (strlen(buff) + 1));
    }

    close(server_sock);
    return 0;
}