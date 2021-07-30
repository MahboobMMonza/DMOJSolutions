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
typedef pair<int, ll> pil;
typedef pair<ll, ll> pl;
typedef pair<ull, ull> pull;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

int dp[255][255][255] {};

int pie(int n, int k, int min) {
    if (!dp[n][k][min]) {
        if (n == k || k == 1) dp[n][k][min] = 1;
        else {
            int t = 0;
            int a = n / k;
            for (int i = min; i <= a; i++) {
                t += pie(n - i, k - 1, i);
            }
            dp[n][k][min] = t;
        }
    }
    return dp[n][k][min];
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    //sbf;
    printf("%d\n", pie(n, k, 1));
    return 0;
}