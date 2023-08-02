#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage: ./server PortNumber\n");
		exit(1);
	}
  int port = atoi(argv[1]);

  int server_sock;
  char buff[BUFF_SIZE];
  int bytes_received;
  struct sockaddr_in server;
  socklen_t sin_size;
  if ((server_sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
  {
		perror("\nError: ");
		return 0;
  }
  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  server.sin_addr.s_addr = INADDR_ANY;
  bzero(&(server.sin_zero), 8);

  if (bind(server_sock, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1)
  {
    perror("\nError in binding server ");
    exit(0);
  }

  int x = 0;
  char prefix[10] = "20194761_";
  while (1)
  {
    struct sockaddr_in client;
    sin_size = sizeof(struct sockaddr_in);
    bytes_received = recvfrom(server_sock, buff, BUFF_SIZE - 1, 0, (struct sockaddr *)&client, &sin_size);

    if (bytes_received == -1) {
      perror("\nError receiving message from client");
      continue;
    }
    buff[bytes_received] = '\0';
    if (strstr(buff, "$") != NULL) {
      x++;
      char temp[2048] = {};
      memset(temp, '\0', sizeof(temp));
      char *token;
      token = strtok(buff, "$");
      char t0[] = "\n";

      char t1[] = "Operating system: ";
      strcat(temp, t1);
      strcat(temp, token);
      strcat(temp, t0);
      token = strtok(NULL, "$");
      char t2[] = "Release: ";
      strcat(temp, t2);
      strcat(temp, token);
      strcat(temp, t0);
      token = strtok(NULL, "$");
      char t3[] = "Version: ";
      strcat(temp, t3);
      strcat(temp, token);
      strcat(temp, t0);
      token = strtok(NULL, "$");
      char t4[] = "Machine: ";
      strcat(temp, t4);
      strcat(temp, token);
      strcat(temp, t0);
      token = strtok(NULL, "$");
      char t5[] = "Hardware model: ";
      strcat(temp, t5);
      strcat(temp, token);
      strcat(temp, t0);
      char t6[] = "Client IP: ";
      char* t7 = inet_ntoa(client.sin_addr);
      strcat(temp, t6);
      strcat(temp, t7);
      strcat(temp, t0);
      char t8[] = "Client port: ";
      char t9[20] = {};
      sprintf(t9, "%d", ntohs(client.sin_port));
      strcat(temp, t8);
      strcat(temp, t9);
      strcat(temp, t0);
      temp[strlen(temp)] = '\0';

      char filename[25];
      memset(filename, '\0', sizeof(filename));
      char xChar[2] = {};
      sprintf(xChar, "%d", x);
      char t[8] = "client_";
      char ext[5] = ".txt";
      FILE *fp;
      strcat(filename, prefix);
      strcat(filename, t);
      strcat(filename, xChar);
      strcat(filename, ext);
      temp[strlen(temp)] = '\0';

      fp = fopen(filename, "w");
      if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
      }
      memset(temp + sizeof(temp) - 1, '\0', 1);
      fwrite(temp, sizeof(char), strlen(temp), fp);

      fclose(fp);

      printf("Wrote client %d to file!\n", x);

      continue;
    }

    int send_len = sendto(server_sock, buff, strlen(buff), 0, (struct sockaddr *)&client, sizeof(client));
    if (send_len == -1)
    {
      perror("Error to send");
      exit(1);
    }
  }
}