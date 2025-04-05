#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>

#define port 9001

int main(){
	int sockfd=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in server_addr;
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(port);
	server_addr.sin_addr.s_addr=INADDR_ANY;
	bind(sockfd,(struct sockaddr *) &server_addr,sizeof(server_addr));
	int n1,n2,max;
	socklen_t len=sizeof(server_addr);
	recvfrom(sockfd,&n1,sizeof(n1),0,(struct sockaddr *) &server_addr,&len);
	printf("\nThe number recieved is : %d",n1);
	recvfrom(sockfd,&n2,sizeof(n2),0,(struct sockaddr *) &server_addr,&len);
	printf("\nThe number recieved is : %d",n2);
	max=(n1>n2)?n1:n2;
	printf("\nThe Maximum is: %d",max);
	sendto(sockfd,&max,sizeof(max),0,(struct sockaddr *) &server_addr,len);
	close(sockfd);
}
