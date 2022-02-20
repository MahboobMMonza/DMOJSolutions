#include <bits/stdc++.h>

using namespace std;

int main() {
    int a = 0, b = 0, x;
    scanf("%d", &x);
    a += 3 * x;
    scanf("%d", &x);
    a += 2 * x;
    scanf("%d", &x);
    a += x;
    scanf("%d", &x);
    b += 3 * x;
    scanf("%d", &x);
    b += 2 * x;
    scanf("%d", &x);
    b += x;
    (a == b) ? printf("T") : (a > b) ? printf("A") : printf("B");
    return 0;
}