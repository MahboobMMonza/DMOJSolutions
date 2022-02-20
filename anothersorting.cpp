#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
    return (a % 10 == b % 10) ? a >= b : a % 10 <= b % 10;
}

int arr[1000000];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++) {
        (i == 0) ? printf("%d", arr[i]) : printf(" %d", arr[i]);
    }
    return 0;
}