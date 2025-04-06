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
	int n,num,rem,count=0,arm=0;
	char msg[100];
	read(client_socket,&n,sizeof(n));
	printf("The number is: %d\n",n);
	num=n;
	bzero(msg,sizeof(msg));
	while(n!=0){
		rem=n%10;
		arm+=(rem*rem*rem);
		n/=10;	
	}
	if(num==arm)
		sprintf(msg,"The number %d is an armstrong number",num);
	else
		sprintf(msg,"The number %d is not an armstrong number",num);
	printf("%s\n",msg);
	write(client_socket,msg,sizeof(msg));
	close(sockfd);
	return 0;
}
