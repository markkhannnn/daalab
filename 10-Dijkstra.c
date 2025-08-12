#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define V 6

int minKey(int key[],bool mset[])
{
    int min,min_index;
    min=INT_MAX;

    for(int i=0;i<V;i++)
    {
        if(!mset[i] && key[i]<min)
            min=key[i],min_index=i;
    }
    return min_index;
}

void Dijkstra(int graph[V][V],int source)
{
    int key[V];
    bool mset[V];
    for(int i=0;i<V;i++)
    {
        key[i]=INT_MAX;
        mset[i]=false;
    }
    key[source]=0;

    for(int count = 0 ;count<V;count++)
    {
        int cur = minKey(key,mset);
        mset[cur]=true;

        for(int v=0;v<V;v++)
        {
            if(!mset[v] && graph[cur][v] && key[cur]!=INT_MAX && key[cur]+graph[cur][v]<key[v])
            {
                key[v]=key[cur]+graph[cur][v];
            }
        }
    }

    printf("VERTEX\t Cost\n");
    char str = 65;
    for(int i=0;i<V;i++)
    printf("%c\t %d\n",str+i,key[i]);


}

int main()
{
    int graph[6][6] = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}};
    Dijkstra(graph, 0);
    return 0;
}
