#include <bits/stdc++.h>

using namespace std;

bool flip(int s) {
    int x = 0, y = s;
    while (s > 0) {
        x *= 10;
        if (s % 10 != 0 && s % 10 != 1 && s % 10 != 8 && s % 10 != 6 && s % 10 != 9) {
            return false;
        } else {
            if (s % 10 == 9) {
                x += 6;
            } else if (s % 10 == 6) {
                x += 9;
            } else {
                x += s % 10;
            }
        }
        s /= 10;
    }
    return y == x;
}

int main() {
    int m, n, c = 0;
    scanf("%d%d", &m, &n);
    for (; m <= n; m++) {
        c += flip(m);
    }
    printf("%d", c);
    return 0;
}