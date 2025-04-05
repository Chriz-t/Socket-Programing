#include<stdio.h>


int main(){
	int dist[100],cost[100][100],flag[100],last[100];
	int min,n,i,j,v,w,src,dest;
	printf("Enter the no of routers:\t");
	scanf("%d",&n);
	printf("Enter the Cost Matrix: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&cost[i][j]);
		}
	}
	printf("Enter the source router:\t");
	scanf("%d",&src);
	printf("Enter the destination router:\t");
	scanf("%d",&dest);
	for(i=0;i<n;i++){
		last[i]=src;
		flag[i]=0;
		dist[i]=cost[src][i];
	}
	flag[src]=1;
	for(i=0;i<n;i++){
		min=1000;
		for(w=0;w<n;w++){
			if(!flag[w]){
				if(dist[w]<min){
					min=dist[w];
					v=w;
				}
			}
		}
		flag[v]=1;
		for(w=0;w<n;w++){
			if(min+cost[v][w]<dist[w]){
				dist[w]=min+cost[v][w];
				last[w]=v;
			}
		}
	}
	int path[100];
	int temp=dest;
	i=0;
	while(temp!=src){
		path[i++]=temp;
		temp=last[temp];
	}
	path[i]=src;
	for(v=i-1;i>=0;i--){
		printf("%d ", path[i]);
        	if(i > 0) printf("-> ");
	}
	
	printf("\nShortest path cost:  %d",dist[dest]);
	
	
}
