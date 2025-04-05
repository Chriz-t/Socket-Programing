#include<stdio.h>

struct router{
	int dist[20];
	int adjNode[20];
}node[20];

int main(){
	int i,j,k,n;
	int costMatrix[20][20];
	printf("Enter the no of Nodes:\t");
	scanf("%d",&n);
	printf("Enter the cost matrix:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&costMatrix[i][j]);
			costMatrix[i][i]=0;
			node[i].dist[j]=costMatrix[i][j];
			node[i].adjNode[j]=j;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if(node[i].dist[j]>costMatrix[i][k]+node[k].dist[j]){
					node[i].dist[j]=costMatrix[i][k]+node[k].dist[j];
					node[i].adjNode[j]=k;
				}
			}
		}
	}
	for(i=0;i<n;i++){
		printf("Router %d:\n",i+1);
		for(j=0;j<n;j++){
			printf("Node %d via %d Distance: %d\n",j+1,node[i].adjNode[j]+1,node[i].dist[j]);
		}
		printf("\n");
	}	
}
