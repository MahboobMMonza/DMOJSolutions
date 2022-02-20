#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, d;
    scanf("%d%d", &m, &d);
    (m < 2) ? printf("Before") : (m == 2 && d == 18) ? printf("Special") : (m == 2 && d < 18) ? printf("Before") : printf("After");
    return 0;
}