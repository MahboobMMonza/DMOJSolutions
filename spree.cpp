#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define fr front()
#define bk back()
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

int dp[1001] = {};

int main() {
    int n, t, v, h;
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &v, &h);
        for (int j = t; j >= h; --j) {
            dp[j] = max(dp[j], dp[j - h] + v);
        }
    }
    printf("%d\n", dp[t]);
}