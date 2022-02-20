#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        int count = 0;
        for (int i = a; i < b; i++) {
            bool flag = 1;
            for (int j = 2; j * j <= i; j++) {
                if (!(i % j)) {flag = 0; break;}
            }
            (i == 1) ? count += 0 : count += flag;
        }
        printf("%d\n", count);
    }
    return 0;
}