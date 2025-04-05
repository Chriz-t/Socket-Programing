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
	connect(sockfd,(struct sockaddr *) &server_addr,sizeof(server_addr));
	//char num1[100],num2[100],sum[100];
	int num1,num2,sum;
	printf("Enter the first no:\t");
	scanf("%d",&num1);
	write(sockfd,&num1,sizeof(num1));
	printf("Enter the second no:\t");
	scanf("%d",&num2);
	write(sockfd,&num2,sizeof(num2));
	read(sockfd,&sum,sizeof(sum));
	printf("The mesage recieved is : %d",sum);
	close(sockfd);
	return 0;
}
