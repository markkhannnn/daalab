
#include <stdio.h>
#include <limits.h>

#define N 4

int cost[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int totalCost(int mask, int curCity, int n) {
    if (mask == (1 << n) - 1) {
        return cost[curCity][0]; // Return to starting city
    }

    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) { // If city i is not visited
            int newAns = cost[curCity][i] + totalCost(mask | (1 << i), i, n);
            if (newAns < ans) {
                ans = newAns;
            }
        }
    }

    return ans;
}

int tsp(int n) {
    return totalCost(1, 0, n); // Start from city 0, mask = 1 (only city 0 is visited)
}

int main() {
    int res = tsp(N);
    printf("Minimum cost of TSP: %d\n", res);
    return 0;
}
