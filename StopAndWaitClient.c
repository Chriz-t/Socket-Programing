#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define port 9001

int main(){
	int sockfd=socket(AF_INET,SOCK_DGRAM,0);
	int n,cf,lost[20],i;
	char msg[100];
	struct sockaddr_in server_addr;
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(port);
	server_addr.sin_addr.s_addr=INADDR_ANY;
	socklen_t len=sizeof(server_addr);
	bind(sockfd,(struct sockaddr *) &server_addr,len);
	printf("Enter the no of total frames:\t");
	scanf("%d",&n);
	printf("Enter the no of corrupted packets:\t");
	scanf("%d",&cf);
	printf("Enter the corrupted frames:\t");
	for(i=0;i<cf;i++){
		scanf("%d",&lost[i]);
	}
	sendto(sockfd,&n,sizeof(n),0,(struct sockaddr *) &server_addr,len);
	sendto(sockfd,&cf,sizeof(cf),0,(struct sockaddr *) &server_addr,len);
	sendto(sockfd,&lost,sizeof(lost),0,(struct sockaddr *) &server_addr,len);
	int count=n+cf;
	for(i=0;i<count;i++){
		bzero(msg,sizeof(msg));
		recvfrom(sockfd,msg,sizeof(msg),0,(struct sock_addr *) &server_addr,&len);
		printf("%s\n",msg);
	}
	close(sockfd);	
}
