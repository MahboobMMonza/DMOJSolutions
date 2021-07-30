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

ll h[100005] = {}, dp[100005] = {};

int main() {
     ll n;
     scanf("%lld", &n);
     for (int i = 0; i < n; i++) {
         scanf("%lld", &h[i]);
     }
     dp[1] = abs(h[0] - h[1]);
     for (int i = 2; i <= n; i++) {
         dp[i] = min(abs(h[i] - h[i - 1]) + dp[i - 1], abs(h[i] - h[i - 2]) + dp[i - 2]);
     }
     printf("%lld", dp[n - 1]);
    return 0;
}