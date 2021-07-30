#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, pii> pil;

int dj[100001] = {0};
char p[100001];

int find(int d) {
    if (dj[d] != d) dj[d] = find(dj[d]);
    return dj[d];
}

int main() {
    int n, m, k, a, b, c = 0;
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s", p);
    for (int i = 1; i <= n; i++) {
        dj[i] = i;
    }
    while (m--) {
        scanf("%d%d", &a, &b);
        if (p[a - 1] == p[b - 1]) {
            dj[find(a)] = find(b);
        }
    }
    while (k--) {
        scanf("%d%d", &a, &b);
        c += (find(a) == find(b));
    }
    printf("%d", c);
    return 0;
}