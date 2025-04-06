#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define port 9001

int main(){
	int sockfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in server_addr;
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(port);
	server_addr.sin_addr.s_addr=INADDR_ANY;
	connect(sockfd,(struct sockaddr *) &server_addr,sizeof(server_addr));
	int n;
	char msg[100];
	printf("Enter the Number:\t");
	scanf("%d",&n);
	write(sockfd,&n,sizeof(n));
	read(sockfd,msg,sizeof(msg));
	printf("%s\n",msg);
	close(sockfd);
	return 0;
}
