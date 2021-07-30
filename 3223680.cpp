#include <bits/stdc++.h>

using namespace std;

char a[1001], b[1001];
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%s%s", &n, a, b);
        for (int i = n - 1; i >= 0; i--) {
            printf("%c%c", b[i], a[i]);
        }
        printf("\n");
    }
    return 0;
}