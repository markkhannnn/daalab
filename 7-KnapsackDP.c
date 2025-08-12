#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Recursive knapsack with memoization
int knapsackRec(int capacity, int profit[], int wt[], int n, int memo[][100]) {
    // Base Case
    if (n == 0 || capacity == 0)
        return 0;

    // If already computed
    if (memo[n][capacity] != -1)
        return memo[n][capacity];

    int pick = 0;

    // Pick nth item if it fits
    if (wt[n - 1] <= capacity)
        pick = profit[n - 1] + knapsackRec(capacity - wt[n - 1], profit, wt, n - 1, memo);

    // Don't pick nth item
    int notPick = knapsackRec(capacity, profit, wt, n - 1, memo);

    // Store and return
    return memo[n][capacity] = max(pick, notPick);
}

int knapsack(int capacity, int profit[], int wt[], int n) {
    int memo[100][100]; // Adjust max size if needed

    // Initialize memo table with -1
    for (int i = 0; i <= n; i++)
        for (int w = 0; w <= capacity; w++)
            memo[i][w] = -1;

    return knapsackRec(capacity, profit, wt, n, memo);
}

int main() {
    int profit[] = {1, 2, 3};
    int wt[] = {4, 5, 1};
    int capacity = 4;
    int n = sizeof(profit) / sizeof(profit[0]);

    printf("%d\n", knapsack(capacity, profit, wt, n));
    return 0;
}