#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll d[7001] = {0};
bitset<7001> m;
int main() {
    m[0] = m[990] = m[1010] = m[1970] = m[2030] = m[2940] = m[3060] = m[3930] = m[4060] = m[4970] = m[5030] = m[5990] = m[6010] = m[7000] = 1;
    int a, b, n, x;
    scanf("%d%d%d", &a, &b, &n);
    while (n--) {
        scanf("%d", &x);
        m[x] = 1;
    }
    d[0] = 1;
    for (int i = 0; i < 7001; i++) {
        for (int j = a; j <= b; j++) {
            if (d[i] && i + j < 7001) {
                if (m[i + j]) d[i + j] += d[i];
            }
        }
    }
    printf("%lld\n", d[7000]);
    return 0;
}