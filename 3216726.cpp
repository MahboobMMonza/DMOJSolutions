#include <bits/stdc++.h>

using namespace std;

int arr[500][500] = {0}, cost[500][500] = {0};
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
            if (i != 0 && j != 0) {
                cost[i][j] = INT_MAX;
            } else {
                cost[i][j] = arr[i][j];
            }
            if (i == 0 && j > 0) cost[i][j] = cost[i][j - 1] + arr[i][j];
            if (i > 0 && j == 0) cost[i][j] = cost[i - 1][j] + arr[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            cost[i][j] = min(min(cost[i][j], cost[i][j - 1] + arr[i][j]), min(cost[i][j], cost[i - 1][j] + arr[i][j]));
        }
    }
    printf("%d", cost[n - 1][m - 1]);
    return 0;
}