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

char s[2005], ss[2005];
const char WA[14] = "WRONGANSWER\n";
int dp[2005][2005] = {};

bool lcs(int n, int k) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (s[i] == ss[j]) ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n] == k;
}

int main() {
    int n, k, f[26] = {}, m = INT32_MAX, c = 0;
    char r = 'z';
    scanf("%d%d%s", &n, &k, s);
    if (k > n) {
        printf("%s", WA);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        f[s[i] - 'a']++;
        c += (f[s[i] - 'a'] == 1);
    }
    if (c < 26) {
        for (int i = 0; i < 26; i++) {
            if (f[i] == 0) { r = (char) ('a' + i); break; }
        }
        for(int i = 0; i < n; i++) {
            if (i < k) {
                printf("%c", s[i]);
            } else {
                printf("%c", r);
            }
        }
        printf("\n");
        return 0;
    }
    for (int i = 0; i < 26; i++) {
        if (m > f[i]) {
            m = f[i];
            r = char ('a' + i);
        }
    }
    int x = 0;
    for (; x < n - k; x++) ss[x] = r;
    for (int i = 0; i < k; i++) ss[i + x] = s[i];
    printf("%s", (lcs(n, k)) ? (string(ss) + "\n").c_str() : WA);
    return 0;
}