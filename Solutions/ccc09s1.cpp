#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, p, c = 0;
    scanf("%d%d", &a, &b);
    for (int i = 1; i <= 22; i++) {
        p = i * i * i * i * i * i;
        c += (p >= a && p <= b);
    }
    printf("%d\n", c);
    return 0;
}