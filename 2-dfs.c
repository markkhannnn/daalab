#include<stdio.h>


int graph[10][10];
int stack[100];

void dfs(int start,int v)
{
    int i,current;
    int top=-1;
    stack[++top]=start;
    int visited[10]={0};
    visited[start]=1;
    while(top!=-1)
    {
        current = stack[top--];
        printf("%d -> ",current);
        for(i=0;i<v;i++)
        {
            if(!visited[i] && graph[current][i])
                {
                    visited[i]=1;
                    stack[++top]=i;
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
    dfs(start,nv);
        return 0;
}