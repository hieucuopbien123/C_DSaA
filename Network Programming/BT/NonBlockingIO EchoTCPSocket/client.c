#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/utsname.h>
#include <stdlib.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 3) {
      printf("Usage: ./client IPAddress PortNumber\n");
      exit(1);
    }
    struct utsname info;
    uname(&info);
    printf("Operating system: %s\n", info.sysname);
    printf("Release: %s\n", info.release);
    printf("Version: %s\n", info.version);
    printf("Machine: %s\n", info.machine);

    char buf[BUFF_SIZE];
    fd_set read_fds;
    char str2[] = "$";
    char str3[] = "\n\0";
    memset(buf, '\0', sizeof(buf));
    strcat(buf, info.sysname);
    strcat(buf, str2);
    strcat(buf, info.version);
    strcat(buf, str2);
    strcat(buf, info.release);
    strcat(buf, str2);
    strcat(buf, info.machine);
    strcat(buf, str2);
    buf[strlen(buf)] = '\0';

    FILE *fp = fopen("/proc/cpuinfo", "r");
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
      if (strncmp(line, "model name", 10) == 0) {
        char *model = strchr(line, ':') + 2;
        printf("Hardware model: %s\n", model);
        strcat(buf, model);
        strcat(buf, str3);
        break;
      }
    }
    fclose(fp);

    int server_port = atoi(argv[2]);

    int server_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_sock == -1)
    {
      perror("socket");
      exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(server_port);

    int flags = fcntl(server_sock, F_GETFL, 0);
    fcntl(server_sock, F_SETFL, flags | O_NONBLOCK);
    int max_fd = server_sock;

    int send_len = sendto(server_sock, buf, strlen(buf), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (send_len == -1)
    {
      perror("Error sendto::");
      exit(1);
    }
    memset(buf, '\0', sizeof(buf));

    while (1)
    {
      FD_ZERO(&read_fds);
      FD_SET(STDIN_FILENO, &read_fds);
      FD_SET(server_sock, &read_fds);

      int ret = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
      if (ret == -1)
      {
        perror("Error on select::");
        exit(1);
      }

      if (FD_ISSET(STDIN_FILENO, &read_fds))
      {
        fgets(buf, BUFF_SIZE, stdin);
        buf[strlen(buf) - 1] = '\0';

        if (strlen(buf) == 0)
        {
          break;
        }

        int send_len = sendto(server_sock, buf, strlen(buf), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (send_len == -1)
        {
          perror("Error on send to::");
          exit(1);
        }
      }

      if (FD_ISSET(server_sock, &read_fds))
      {
        socklen_t server_resp_len = sizeof(server_addr);
        int recv_len = recvfrom(server_sock, buf, BUFF_SIZE, 0, (struct sockaddr *)&server_addr, &server_resp_len);
        if (recv_len == -1)
        {
          perror("Error on Receive::");
          exit(1);
        }
        buf[recv_len] = '\0';
        printf("From server::%s\n", buf);
      }
    }
    close(server_sock);
    return 0;
}
