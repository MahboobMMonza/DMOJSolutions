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

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

ll psa[(int) 1e6 + 5];

int main() {
    int n, k;
    ll m, x, ans = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &m, &x);
        psa[x + 1] += m;
    }
    for (int i = 1; i < 1e6 + 5; i++) {
        psa[i] += psa[i - 1];
    }
    for (int i = 1; i < 1e6 + 5; i++) {
        ans = max(ans, psa[min((int) 1e6 + 4, i + k)] - psa[max(0, i - k - 1)]);
    }
    printf("%lld\n", ans);
    return 0;
}