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

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

ll dp[100005] = {};

int main() {
    ll n, w, v, wi;
    scanf("%lld%lld", &n, &w);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &wi, &v);
        for (int j = w; j >= wi; j--) {
            dp[j] = max(dp[j], dp[j - wi] + v);
        }
    }
    printf("%lld", dp[w]);
    return 0;
}