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
#define qu queue
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

double h[10'002] {};

int main() {
    int n;
    double a = 0, w;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        scanf("%lf", &h[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lf", &w);
        a += min(h[i], h[i + 1]) * w + (abs(h[i] - h[i + 1]) * (w / 2.0));
    }
    printf("%lf\n", a);
    return 0;
}