#include <bits/stdc++.h>

using namespace std;

int y(int a, int b, int s) {
    int x = s / (a + b) * (a - b);
    s %= a + b;
    return (s <= a) ? x + s : x + a + a - s; 
}

int main() {
    int a, b, c, d, s, n, m;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &s);
    n = y(a, b, s);
    m = y(c, d, s);
    (n == m) ? printf("Tied") : (n > m) ? printf("Nikky") : printf("Byron");
    return 0;
}