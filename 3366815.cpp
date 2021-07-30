#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define fr front()
#define bk back()
#define ppf pop_front()
#define tp top()
#define ps push
#define pp pop()

typedef unsigned long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

struct cg {
    int n = 0, k = 0;

    friend bool operator<(const cg a, cg b) {
        return (a.n == b.n) ? a.k < b.k : a.n > b.k;
    }
} cgs[1005];

int dp[1005][1005] = {};

int ks(int c, int t) {
    if (dp[c][t] != 0 || c == 0 || t == 0) return dp[c][t];
    int r;
    if (cgs[c].k > t) {
        r = ks(c - 1, t);
    } else {
        r = max(ks(c - 1, t), cgs[c].n + ks(c - 1, t - cgs[c].k));
    }
    dp[c][t] = r;
    return r;
}

int main() {
    int c, m;
    scanf("%d%d", &c, &m);
    for (int i = 1; i <= c; i++) {
        scanf("%d%d", &cgs[i].n, &cgs[i].k);
    }
    sort(cgs + 1, cgs + c + 1);
    printf("%d\n", ks(c, m));
    return 0;
}