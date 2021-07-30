#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, s = 0;
    scanf("%d%d", &n, &k);
    s = n;
    while (k--) {
        s += (n *= 10);
    }
    printf("%d", s);
    return 0;
}