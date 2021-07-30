#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define fr front()
#define bk back()
#define sbf setbuf(stdout, 0)
#define ppf pop_front()
#define tp top()
#define ps push
#define pp pop()
#define fls fflush(stdout)
#define qu queue
#define st stack
#define pq priority_queue

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pl;
typedef pair<ull, ull> pull;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;
typedef pair<pi, pi> ppi;

int R, C, K;
unordered_map<ll, int> mp;

int q(int r, int c) {
    ll k = (ll) 1e9 * r + c;
    if (mp.count(k)) return mp[k];
    printf("? %d %d\n", r, c);
    int x;
    scanf("%d", &x);
    fflush(stdout);
    mp[k] = x;
    return x;
}

int main() {
    scanf("%d%d%d", &R, &C, &K);
    int r1 = 1, r2 = R, c1 = 1, c2 = C, ans;
    while (r1 < r2 || c1 < c2) {
        int rm = (r1 + r2)>>1, cm = (c1 + c2)>>1;
        if (r1 < r2) {
            int cn = q(rm, cm), ri = q(rm + 1, cm);
            if (cn < ri) r2 = rm;
            else r1 = rm + 1;
        }
        if (c1 < c2) {
            int cn = q(rm, cm), ri = q(rm, cm + 1);
            if (cn < ri) c2 = cm;
            else c1 = cm + 1;
        }
    }
    ans = q(r1, c1);
    printf("! %d\n", ans);
    return 0;
}