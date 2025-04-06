#include<stdio.h>
#include<string.h>
#include<netdb.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define port 9001

int main(){
	char buffer[1024]={0},command[20]={0},fileName[20]={0};
	int n;
	int sockfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in server_addr;
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(port);
	server_addr.sin_addr.s_addr=INADDR_ANY;
	bind(sockfd,(struct sockaddr *) &server_addr,sizeof(server_addr));
	listen(sockfd,5);
	int client_fd=accept(sockfd,NULL,NULL);
	read(client_fd,command,sizeof(command));
	read(client_fd,fileName,sizeof(fileName));
	FILE *fp;
	if(strcmp(command,"put")==0){
		fp=fopen("newPutFile.txt","w");
		while((n=read(client_fd,buffer,sizeof(buffer)))>0){
			fwrite(buffer,sizeof(char),n,fp);
		}
		fclose(fp);
	}else if(strcmp(command,"get")==0){
		fp=fopen(fileName,"r");
		while((n=fread(buffer,sizeof(char),sizeof(buffer),fp))>0){
			write(client_fd,buffer,n);
		}
		fclose(fp);
	}
	close(client_fd);
}
