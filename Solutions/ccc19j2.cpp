#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    char c;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %c", &x, &c);
        while (x--) {
            printf("%c", c);
        }
        printf("\n");
    }
    return 0;
}