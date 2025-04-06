#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define port 9001
struct table{
	int key;
	char value[100];
}TB[5];
int main(){
	TB[0].key=100;
	strcpy(TB[0].value,"Star");
	TB[1].key=101;
	strcpy(TB[1].value,"Flower");
	TB[2].key=102;
	strcpy(TB[2].value,"Fire");
	TB[3].key=103;
	strcpy(TB[3].value,"Shadow");
	TB[4].key=104;
	strcpy(TB[4].value,"Time");
		
	
	int server_socket=socket(AF_INET, SOCK_STREAM, 0);
	if(server_socket<0){
		perror("ERROR opening socket!");
	}
	
	struct sockaddr_in server_addr,client_addr;
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(port);
	server_addr.sin_addr.s_addr=INADDR_ANY;
	
	int bn=bind(server_socket,(struct sockaddr*) &server_addr,sizeof(server_addr));
	if(bn<0){
		perror("ERROR binding socket!");
	}
	
	
	int ls=listen(server_socket,5);
	if(ls<0){
		perror("ERROR listening socket!");
	}
	
	int client_socket=accept(server_socket,NULL,NULL);
	
	char buffer[256],strvalue[256],temp;
	bzero(buffer,256);
	int re=read(client_socket,buffer,255);
	printf("Key:%s",buffer);
	for(int i=0;i<5;i++){
		if(TB[i].key==atoi(buffer)){
			strcpy(strvalue,TB[i].value);
			break;
		}
		strcpy(strvalue,"The key is not found");
	}
	//printf("\nThe message is recieved: %s",buffer);
	
	//int len=strlen(buffer),j=0;
	//for(int i=len-1;i>=0;i--){
	//	rev[j++]=buffer[i];
	//}
	
	int wr=write(client_socket,/*rev*/strvalue,sizeof(strvalue));
	
	close(server_socket);
	
	return 0;
	}
