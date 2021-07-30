#include <bits/stdc++.h>

using namespace std;

#define fs first
#define fio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
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

int min(const size_t & a, const size_t & b, const size_t & c) {
    return min(c, min(a, b));
}

size_t dp[2][1005] {};

int ld() {
    size_t D, I, R;
    string a, b;
    cin >> D >> I >> R >> a >> b;
    R = min(D + I, R);
    for (size_t i = 0; i <= a.length(); i++) {
        dp[0][i] = i * D;
    }
    for (size_t i = 1; i <= b.length(); i++) {
        for (size_t j = 0; j <= a.length(); j++) {
            if (!j) dp[i & 1][j] = i * I;
            else dp[i & 1][j] = (a[j - 1] == b[i - 1]) ? dp[(i - 1) & 1][j - 1] : min(D + dp[i & 1][j - 1], I + dp[(i - 1) & 1][j], R + dp[(i - 1) & 1][j - 1]);
        }
    }
    return dp[b.length() & 1][a.length()];
}

int main() {
    fio;
    cout << ld() << "\n";
    return 0;
}