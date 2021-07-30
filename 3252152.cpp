#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, q, t = 0;
    scanf("%d%d%d%d", &q, &a, &b, &c);
    while (q > 0) {
        q--;
        a++;
        t++;
        if (a == 35) {
            a = 0;
            q += 30;
        }
        if (q == 0) break;
        q--;
        b++;
        t++;
        if (b == 100) {
            b = 0;
            q += 60;
        }
        if (q == 0) break;
        q--;
        c++;
        t++;
        if (c == 10) {
            c = 0;
            q += 9;
        }
    }
    printf("Martha plays %d times before going broke.", t);
    return 0;
}