#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    (x > 0) ? (y > 0) ? printf("1") : printf("4") : (y > 0) ? printf("2") : printf("3");
    return 0;
}