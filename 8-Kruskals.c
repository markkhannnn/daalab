#include<stdio.h>
#include<stdlib.h>

int comparator(const void *p1, const void *p2)
{
    const int *a = p1;
    const int *b = p2;
    return a[2] - b[2];
}
void makeset(int parent[],int n){
    for(int i=0;i<n;i++)
         parent[i]=i;
            
        
}

int findParent(int parent[],int node){
    if(parent[node]==node)
        return node;

        return parent[node]=findParent(parent,parent[node]);
}

void unionSet(int u,int v, int parent[])// USING SIMPLE UNION INSTEAD OF WEIGHTED UNION
{
    u=findParent(parent,u);
    v=findParent(parent,v);
    parent[v]=u;
}

int kruskals(int n, int edge[n][3])
{
    qsort(edge,n,sizeof(edge[0]),comparator);
    int parent[n];
    makeset(parent,n);
    int mincost = 0;

    for(int i=0;i<n;i++)
    {
        int v1=findParent(parent,edge[i][0]);
        int v2=findParent(parent,edge[i][1]);
        int weight = edge[i][2];

        if(v1!=v2)
        {
            unionSet(v1,v2,parent);
            mincost+=weight;
        }
    }
    return mincost;
}

int main()
{
    printf(" number of edges : ");
    int edge[10][3];
    int n;
    scanf("%d",&n);
    printf("Enter src, dst, weight");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&edge[i][0],&edge[i][1],&edge[i][2]);
    }
    int mincost = kruskals(n,edge);
    printf("minimum cost is %d\n",mincost);

    return 0;
}