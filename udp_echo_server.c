#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define port 9001

int main(){
	int sockfd=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in server_addr,client_addr;
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(port);
	server_addr.sin_addr.s_addr=INADDR_ANY;
	bind(sockfd,(struct sockaddr *) &server_addr,sizeof(server_addr));
	char str[100];
	socklen_t len=sizeof(server_addr);
	recvfrom(sockfd,str,sizeof(str),0,(struct sockaddr *) &client_addr,&len);
	printf("The message recieved is: %s\n",str);
	sendto(sockfd,str,sizeof(str),0,(struct sockaddr *) &client_addr,len);
	printf("The message send: %s\n",str);
	close(sockfd);
}
