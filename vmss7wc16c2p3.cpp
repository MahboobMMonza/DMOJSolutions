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

size_t lcs(vector<int> & a, vector<int> & b) {
    unordered_map<int, size_t> idxB;
    vector<int> c, lis;
    for (size_t i = 0; i < b.size(); i++) {
        idxB[b[i]] = i + 1;
    }
    for (size_t i = 0; i < a.size(); i++) {
        if (idxB.count(a[i])) c.pb(idxB[a[i]]);
    }
    for (size_t i = 0; i < c.size(); i++) {
        if (lis.empty() || lis.back() < c[i]) lis.pb(c[i]);
        else if (c[i] <= lis[0]) lis[0] = c[i];
        else *lower_bound(lis.begin(), lis.end(), c[i]) = c[i];
    }
    return lis.size();
}

int main() {
    fio;
    int n;
    cin >> n;
    vector<int> a (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> n;
    vector<int> b (n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    cout << lcs(a, b) << "\n";
    return 0;
}