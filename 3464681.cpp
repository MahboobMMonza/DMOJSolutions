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

string s;

bitset<1002> c[1002];

int sum(int rs, int cs, int re, int ce) {
    int r = 0;
    for (int i = rs; i <= re; i++) {
        for (int j = cs; j <= ce; j++) {
            r += c[i][j];
        }
    }
    return r;
}

int main() {
    fio;
    int n, cnt;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= n; j++) {
            c[i][j] = (s[j - 1] == 'R');
        }
    }
    for (int j = 1; j <= n; j++) {
        if (c[1][j]) {
            for (int i = 1; i <= n; i++) {
                c[i].flip(j);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (c[i][1]) c[i].flip();
    }
    cnt = sum(1, 1, n, n);
    if (cnt == 1) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (c[i][j]) cout << i << ' ' << j << '\n';
            }
        }
        return 0;
    }
    if (cnt == (n - 1) * (n - 1)) {
        cout << "1 1\n";
        return 0;
    }
    if (cnt == n - 1) {
        for (int i = 1; i <= n; i++) {
            if (sum(i, 1, i, n) == n - 1) { cout << i << " 1\n"; return 0; }
            if (sum(1, i, n, i) == n - 1) {cout << "1 " << i << '\n'; return 0; }
        }
    }
    cout << "-1\n";
    return 0;
}