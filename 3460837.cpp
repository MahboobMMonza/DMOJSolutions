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

vector<int> lis;

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (lis.empty() || lis.back() < x) { lis.pb(x); }
        else if (lis[0] >= x) lis[0] = x;
        else {
            *lower_bound(lis.begin(), lis.end(), x)= x;
        }
    }
    printf("%u\n", lis.size());
    return 0;
}