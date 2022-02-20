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


int main() {
    stack<char> vow, cons;
    int n, c, v;
    char x;
    scanf("%d%d%d%*c", &n, &c, &v);
    for (int i = 0; i < n; ++i) {
        scanf("%c", &x);
        if (x == 'y') {
            vow.ps(x);
            cons.ps(x);
        } else if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
            if (!cons.empty()) cons = {};
            vow.ps(x);
        } else {
            if (!vow.empty()) vow = {};
            cons.ps(x);
        }
        if (vow.size() > v) {
            sbf;
            printf("NO\n");
            return 0;
        }
        if (cons.size() > c) {
            sbf;
            printf("NO\n");
            return 0;
        }
    }
    sbf;
    printf("YES\n");
    return 0;
}