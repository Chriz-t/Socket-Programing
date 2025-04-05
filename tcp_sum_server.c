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
	bind(sockfd,(struct sockaddr *) &server_addr,sizeof(server_addr));
	listen(sockfd,3);
	int client_socket=accept(sockfd,NULL,NULL);
	int n1,n2,n3;
	read(client_socket,&n1,sizeof(n1));
	printf("The first num is: %d\n",n1);
	read(client_socket,&n2,sizeof(n2));
	printf("The second num is: %d\n",n2);
	n3=n1+n2;
	printf("The num send is: %d\n",n3);
	write(client_socket,&n3,sizeof(n3));
	close(sockfd);
	return 0;
}
