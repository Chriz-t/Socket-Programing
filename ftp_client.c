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
	connect(sockfd,(struct sockaddr *) &server_addr,sizeof(server_addr));
	printf("Enter the command:\t");
	scanf("%s",command);
	write(sockfd,command,sizeof(command));
	printf("Enter the file name:\t");
	scanf("%s",fileName);
	write(sockfd,fileName,sizeof(fileName));
	FILE *fp;
	if(strcmp(command,"put")==0){
		fp=fopen(fileName,"r");
		while((n=fread(buffer,sizeof(char),sizeof(buffer),fp))>0){
			write(sockfd,buffer,n);
		}
		fclose(fp);
	}else if(strcmp(command,"get")==0){
		fp=fopen("newGetFile.txt","w");
		while((n=read(sockfd,buffer,sizeof(buffer)))>0){
			fwrite(buffer,sizeof(char),n,fp);
		}
		fclose(fp);
	}
	close(sockfd);
}
