#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define V 5
#include<stdbool.h>
int minKey(int key[],bool mstset[] )
{
    int min = INT_MAX,min_index;
    for(int i=0;i<V;i++)
    {
        if(!mstset[i]&&key[i]<min)
            min=key[i],min_index=i;
    }
    return min_index;
}

void printMst(int parent[],int graph[V][V])
{
    int cost=0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++){
        printf("%d - %d \t%d \n", parent[i], i,
            graph[parent[i]][i]);
            cost+=graph[parent[i]][i];
        }
        printf("Min cost is %d\n",cost);
}

void prims(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstset[V];

    for (int i = 0; i < V; i++)
    {
        key[i]=INT_MAX;
        mstset[i]=false;
    }

    key[0]=0;
    parent[0]=-1;

    for (int  i = 0; i < V-1;i++)
    {
        int cur = minKey(key,mstset);
        mstset[cur]=true;
        for(int v=0;v<V;v++)
        {
            if(graph[cur][v] && !mstset[v] && graph[cur][v]<key[v])
            {
                key[v]=graph[cur][v],parent[v]=cur;
            }
        }
    }
    
    printMst(parent,graph);
    
}

int main(int argc, char const *argv[])
{
    int graph[V][V];
    printf("Enter cost matrix : ");
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            scanf("%d",&graph[i][j]);
    prims(graph);
    return 0;
}
