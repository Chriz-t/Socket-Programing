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
	struct sockaddr_in server_addr,client_addr;
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(port);
	server_addr.sin_addr.s_addr=INADDR_ANY;
	bind(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr));
	listen(sockfd,3);
	int client_socket=accept(sockfd,NULL,NULL);
	char buffer[256],temp;
	bzero(buffer,sizeof(buffer));
	read(client_socket,buffer,sizeof(buffer));
	printf("The message recieved: %s\n",buffer);
	int len=strlen(buffer);
	for(int i=0;i<len/2;i++){
		temp=buffer[i];
		buffer[i]=buffer[len-i-1];
		buffer[len-i-1]=temp;
	}
	printf("The message sent: %s\n",buffer);
	write(client_socket,buffer,sizeof(buffer));
	close(sockfd);
	return 0;
	
}
