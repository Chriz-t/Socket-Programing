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
	int n,cf,lost[20],i,j=0;
	char msg[100];
	struct sockaddr_in server_addr;
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(port);
	server_addr.sin_addr.s_addr=INADDR_ANY;
	socklen_t len=sizeof(server_addr);
	bind(sockfd,(struct sockaddr *) &server_addr,len);
	recvfrom(sockfd,&n,sizeof(n),0,(struct sock_addr *) &server_addr,&len);
	recvfrom(sockfd,&cf,sizeof(cf),0,(struct sock_addr *) &server_addr,&len);
	recvfrom(sockfd,&lost,sizeof(lost),0,(struct sock_addr *) &server_addr,&len);
	for(i=0;i<n;i++){
		bzero(msg,sizeof(msg));
		if(lost[j]==i){
			j++;
			printf("Send packet %d\n",i);
			sleep(2);
			sprintf(msg,"Packet %d not recieved\nSending NAK",i);
			printf("Packet %d not recieved\n",i);
			sendto(sockfd,msg,sizeof(msg),0,(struct sockaddr *) &server_addr,len);
			sleep(2);
			bzero(msg,sizeof(msg));
			sprintf(msg,"Recieved packet %d\nSending ACK %d",i,i);
			printf("Sent packet %d\n",i);
			sendto(sockfd,msg,sizeof(msg),0,(struct sockaddr *) &server_addr,len);
			sleep(2);
		}else{
		sprintf(msg,"Recieved packet %d\nSending ACK %d",i,i);
		printf("Sent packet %d\n",i);
		sendto(sockfd,msg,sizeof(msg),0,(struct sockaddr *) &server_addr,len);
		sleep(2);
		}
	}
	close(sockfd);
}
