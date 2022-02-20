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
#define qu queue
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

bitset<5000000> r, c;

int main() {
    int m, n, k, ra = 0, ca = 0, v;
    char x;
    scanf("%d%d%d%*c", &m, &n, &k);
    while (k--) {
        scanf("%c%*c%d%*c", &x, &v);
        if (x == 'R') {
            (r[v]) ? ra-- : ra++;
            r[v]  = !r[v];
        } else {
            (c[v]) ? ca-- : ca++;
            c[v]  = !c[v];
        }
    }
    printf("%d\n", n * ra + m * ca - (ra * ca * 2));
    return 0;
}