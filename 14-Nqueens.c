#include <stdio.h>
#include <math.h>
#include<stdlib.h>
int board[20], count;
void print(int n)
{
    int i, j;
    printf("\n\nSolution %d:\n\n", ++count);
    for (i = 1; i <= n; ++i)
        printf("\t%d", i);
    for (i = 1; i <= n; ++i)
    {
        printf("\n\n%d", i);
        for (j = 1; j <= n; ++j)
        {
            if (board[i] == j)
                printf("\tQ");
            else
                printf("\t-");
        }
    }
}
int place(int row, int column)
{
    for (int i = 1; i <row ; ++i)
    {
        if (board[i] == column || abs(board[i] - column) == abs(i - row))
            return 0;
    }
    return 1;
}
void queen(int row, int n)
{
    for (int column = 1; column <= n; ++column)
    {
        if (place(row, column))
        {
            board[row] = column;
            if (row == n)
                print(n);
            else
                queen(row + 1, n);
        }
    }
}
int main()
{
    int n;
    printf(" - N Queens Problem Using Backtracking -");
    printf("\n\nEnter number of Queens: ");
    scanf("%d", &n);
    queen(1, n);
    return 0;
}