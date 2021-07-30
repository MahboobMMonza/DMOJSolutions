#include <bits/stdc++.h>

using namespace std;

bitset<100010> gt;

int main() {
    int g, p, n, l;
    scanf("%d%d", &g, &p);
    gt.flip();
    for(int i = 0; i < p; i++) {
        scanf("%d", &l);
        n = gt._Find_next(g - l);
        if (n > g) {
            printf("%d", i);
            return 0;
        }
        gt[n] = 0;
    }
    printf("%d", p);
    return 0;
}