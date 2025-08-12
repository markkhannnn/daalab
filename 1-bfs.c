#include<stdio.h>
#include<stdlib.h>
int graph[100][100];

void bfs(int start,int vertices)
{
    int queue[100],front=0,rear=0;
    queue[rear++]=start;
    int visited[100]={0};
    visited[start]=1;
    while(front!=rear)
    {
        int current = queue[front++];
        printf("%d -> ",current);
        for(int i=0;i<vertices;i++)
        {
            if(!visited[i] && graph[current][i])
            {
                visited[i] = 1;
                queue[rear++]=i;
            }
        }
    }

}

int main()
{
    int nv,ne;
    printf("Enter number of vertices and edges : ");
    scanf("%d%d",&nv,&ne);
    int src,dst;
    printf("Enter edges pairs : ");
    for(int i = 0 ; i<ne;i++)
        {
                scanf("%d%d",&src,&dst);
                graph[src][dst]=graph[dst][src]=1;
        }
    int start;
    printf("Enter start node : ");
    scanf("%d",&start);
    bfs(start,nv);
        return 0;
}