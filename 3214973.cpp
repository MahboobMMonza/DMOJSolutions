#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, p, r, c = 0;
    scanf("%d%d%d", &p, &n, &r);
    int i = n;
    while (n <= p) {
        n += (i *= r);
        c++;
    }
    printf("%d", c);
    return 0;
}