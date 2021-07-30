#include <bits/stdc++.h>

using namespace std;

int main() {
    int q, c = 0, m = -1, t[3] = {}, po[] {30, 60, 9}, pc[] {35, 100, 10};
    scanf("%d%d%d%d", &q, &t[0], &t[1], &t[2]);
    while (q  > 0) {
        m = (m + 1) % 3;
        q--;
        c++;
        t[m]++;
        if (t[m] == pc[m]) {
            t[m] = 0;
            q += po[m];
        }
    }
    printf("Martha plays %d times before going broke.\n", c);
    return 0;
}