#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", (n == 2) ? 2 : n - 1);
    }
    return 0;
}