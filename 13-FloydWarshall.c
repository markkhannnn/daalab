#include <stdio.h>
int min(int a, int b)
{
    return (a < b) ? a : b;
}
void floyds(int p[10][10], int n)
{
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (i == j)
                    p[i][j] = 0;
                else
                    p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}
void main()
{
    int w, n, e, i, j;
    n = 3;
    e = 3;
    int p[10][10];
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            p[i][j] = 999;
    }
    p[1][2] = 10;
    p[2][3] = 15;
    p[3][1] = 12;
    printf("\nMatrix of input data:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d \t", p[i][j]);
        printf("\n");
    }
    floyds(p, n);
    printf("\nTransitive closure:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d \t", p[i][j]);
        printf("\n");
    }
    printf("\nThe shortest paths are:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (i != j)
                printf("\n<%d,%d> = %d", i, j, p[i][j]);
}