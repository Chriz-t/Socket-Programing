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
	bind(sockfd,(struct sockaddr*) &server_addr,sizeof(server_addr));
	int num1,num2,max;
	socklen_t len=sizeof(server_addr);
	printf("Enter the first number: \t");
	scanf("%d",&num1);
	sendto(sockfd,&num1,sizeof(num1),0,(struct sockaddr *) &server_addr,len);
	printf("Send number: %d",num1);
	printf("\nEnter the second number: \t");
	scanf("%d",&num2);
	sendto(sockfd,&num2,sizeof(num2),0,(struct sockaddr *) &server_addr,len);
	printf("Send number: %d",num2);
	recvfrom(sockfd,&max,sizeof(max),0,(struct sockaddr *) &server_addr,&len);
	printf("\nThe max recieved is: %d",max);
	close(sockfd);
}
