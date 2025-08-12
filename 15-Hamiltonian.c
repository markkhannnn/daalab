#include <stdio.h>
#define N 5
int graph[N][N] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}};
int path[N];
void displayCycle()
{
    printf("Cycle Found: ");
    for (int i = 0; i < N; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]);
}
int isValid(int v, int k)
{
    if (graph[path[k - 1]][v] == 0)
        return 0;
    for (int i = 0; i < k; i++)
        if (path[i] == v)
            return 0;
    return 1;
}
int cycleFound(int k)
{
    if (k == N)
    {
        if (graph[path[k - 1]][path[0]] == 1)
            return 1;
        else
            return 0;
    }
    for (int v = 1; v < N; v++)
    {
        if (isValid(v, k))
        {
            path[k] = v;
            if (cycleFound(k + 1) == 1)
                return 1;
            path[k] = -1;
        }
    }
    return 0;
}
int hamiltonianCycle()
{
    for (int i = 0; i < N; i++)
        path[i] = -1;
    path[0] = 0;
    if (cycleFound(1) == 0)
    {
        printf("Solution does not exist\n");
        return 0;
    }
    displayCycle();
    return 1;
}
int main()
{
    hamiltonianCycle();
    return 0;
}