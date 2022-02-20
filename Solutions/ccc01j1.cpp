#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, c = 1;
    scanf("%d", &n);
    for (int l = 0; l < n; l++) {
        for (int i = 0; i < c; i++) {
            printf("*");
        }
        for (int i = 0; i < 2 * (n - c); i++) {
            printf(" ");
        }
        for (int i = 0; i < c; i++) {
            printf("*");
        }
        printf("\n");
        if (l < n / 2) {
            c += 2;
        } else {
            c -= 2;
        }
    }
    return 0;
}