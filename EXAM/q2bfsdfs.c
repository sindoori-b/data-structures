#include<stdio.h>
int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1,reach[20];

void bfs(int v)
 {
 for(i = 1; i <= n; i++)
 if(a[v][i] && !visited[i])
 q[++r] = i;
 if(f <= r) {
 visited[q[f]] = 1;
 bfs(q[f++]);
 }
}
void dfs(int v)
{
	int i;
	reach[v]=1;
	for (i=1;i<=n;i++)
	  if(a[v][i] && !reach[i])
	   {
		printf("\n %d->%d",v,i);
		dfs(i);
	}
	
}

int main() 
{
 int v,ch,count=0;
 printf("\n Enter the number of vertices:");
 scanf("%d", &n);
 for(i=1; i <= n; i++)
  {
	  q[i] = 0;
	  visited[i] = 0;
	  reach[i]=0;
 }
 printf("\n Enter the adjecncy matrix \n");
 for(i=1; i<=n; i++)
  {
 for(j=1;j<=n;j++)
  {
 scanf("%d", &a[i][j]);
 }
 }
 printf("\n Enter the starting vertex:");
 scanf("%d", &v);
 
 printf("1: BFS \n2: DTS \nEnter your Choice\n");
 scanf("%d",&ch);
 switch(ch)
 {
	 case 1:printf("BTS is :\n");
			bfs(v);
			printf("\n The node which are reachable are:\n");
			for(i=1; i <= n; i++)
			{
			if(visited[i])
			printf("%d\t", i);
			else
			{
			printf("\n Bfs is not possible. Not all nodes are reachable");
			break;
			}
			}
			break;
  
	case 2: printf("DFS is \n");
			dfs(1);
			printf("\n");
			for (i=1;i<=n;i++)
				{
					if(reach[i])
					count++;
				}
			if(count==n)
			printf("\n Graph is connected"); else
			printf("\n Graph is not connected");

			break;
	default :printf("inavlid entry");
}

}

