#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct q{ll a, p; };

struct compare {
    bool operator()(q const& x, q const& y)
    {return x.a >= y.a;}
};
int main() {
    ll n, l, s, a, b, p, c = 0, h;
    bool f = 0;
    scanf("%lld%lld%lld", &n, &l, &s);
    priority_queue<q, vector<q>, compare> pq;
    while (n--) {
        scanf("%lld%lld%lld", &a, &b, &p);
        pq.push(q{a, p});
        pq.push(q{b + 1, -p});
    }
    h = l;
    b = l;
    a = 0;
    while (!pq.empty()) {
        q x = pq.top(); pq.pop();
        c += x.p;
        if (c >= s && !f) {
            f = 1;
            b = x.a;
            a = l;
        }
        if (f && c < s) {
            f = 0;
            a = x.a;
            h -= a - b;
        }
    }
    if (a == l) {
        h -= a - b;
    }
    printf("%lld", h);
    return 0;
}