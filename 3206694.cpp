#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, m;
    scanf("%d%d", &x, &m);
    for (int i = 1; i < m; i++) {
        if ((x * i) % m == 1) {
            printf("%d", i);
            return 0;
        }
    }
    printf("No such integer exists.");
    return 0;
}