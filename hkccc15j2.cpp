#include <bits/stdc++.h>

using namespace std;

int arr[100][2] = {0};
int main() {
    int n, a = (int) 2e9;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &arr[i][0], &arr[i][1]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            a = min(a, max( abs(arr[i][0] - arr[j][0]), abs(arr[j][1] - arr[i][1])));
        }
    }
    printf("%d", a * a);
    return 0;
}