#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n, arr[] = {-1, 1, 2, 4, 7, 8, 11, 13, 14};
    scanf("%d", &n);
    printf("%d\n", (15 * (n / 8)) + arr[n % 8]);
    return 0;
}