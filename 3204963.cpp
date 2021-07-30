#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    (n <= 5) ? printf("%d", n / 2 + 1) : printf("%d", (10 - n) / 2 + 1);
    return 0;
}