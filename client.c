//client
/*
实现功能:在客户端输入任意字符串，在服务器端将接收到的内容显示
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <memory.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
 
#define BUF_SIZE 64
int main()
{
	int cliSockFd;
	char sendMsg[BUF_SIZE];
	char recvMsg[BUF_SIZE];
	int recvLen;
	int sendLen;
	struct sockaddr_in  srvAddr;
	printf("%d\r\n", __LINE__);
	srvAddr.sin_family = AF_INET;
	srvAddr.sin_port = htons(5000);
	inet_aton("127.0.0.1", &srvAddr.sin_addr);
	printf("%d\r\n", __LINE__);
	if((cliSockFd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket");
		return -1;
	}
	
	if(connect(cliSockFd, (struct sockaddr*)&srvAddr, sizeof(struct sockaddr)) < 0)
	{
		perror("connect");
		return -1;
	}
	printf("Connected to server\r\n");
	sleep(10);
	while(1)
	{
		memset(sendMsg, 0, sizeof(sendMsg));
		printf("please input mssege to send:\r\n");
		scanf("%s", sendMsg);
		if(0 == strcmp("quit", sendMsg))
		{
			break;
		}
		sendLen = send(cliSockFd, sendMsg, strlen(sendMsg), 0);
		printf("sendLen=%d\r\n", sendLen);
 
	}
 
	close(cliSockFd);
	sleep(10);
	return 0;
}
