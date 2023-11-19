#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <functional>
#include <limits>
#include <vector>

using namespace std;

#define fs first
#define fio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sc second
#define pb push_back
#define eb emplace_back
#define edl '\n'
#define pf push_front
#define ppb pop_back()
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
#define fora(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define forae(i, a, b, c) for (int i = (a); i <= (b); i += (c))
#define ford(i, a, b, c) for (int i = (a); i > (b); i -= (c))
#define forde(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
#define foral(i, a, b, c) for (long long i = (a); i < (b); i += (c))
#define forael(i, a, b, c) for (long long i = (a); i <= (b); i += (c))
#define fordl(i, a, b, c) for (long long i = (a); i > (b); i -= (c))
#define fordel(i, a, b, c) for (long long i = (a); i >= (b); i -= (c))
#define MX (size_t)(2e5 + 5)

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pl;
typedef pair<ull, ull> pull;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;
typedef pair<pi, pi> ppi;
typedef pair<char, int> pci;

inline ll mulMod(ll x, ll y, ll m = LONG_LONG_MAX) {
    x %= m;
    ll res = 0;
    while (y) {
        if (y & 1)
            res = (res + x) % m;
        if (res < 0)
            res += m;
        x = (x << 1) % m;
        y >>= 1;
    }
    return res % m;
}

inline ll logPow(ll x, ll y, ll m = LONG_LONG_MAX) {
    x %= m;
    ll res = 1;
    while (y) {
        if (y & 1)
            res = mulMod(res, x, m);
        x = mulMod(x, x, m);
        y >>= 1;
    }
    return res % m;
}

inline ll fsLogPow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1)
            res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

inline ll pLogPow(ll x, ll y, ll m = 9223372036854775783) { return logPow(x, y % (m - 1), m); }

int findParent(vector<int> &parent, st<int> &stk, int x) {
    while (parent[x] != x) {
        stk.ps(x);
        x = parent[x];
    }
    while (!stk.empty()) {
        parent[stk.tp] = x;
        stk.pp;
    }
    return x;
}

bool join(vector<int> &parent, vector<int> &rank, st<int> &stk, int node1, int node2) {
    int p1 = findParent(parent, stk, node1), p2 = findParent(parent, stk, node2);
    if (p1 == p2) {
        return false;
    }
    if (rank[p1] < rank[p2] || rank[p1] == rank[p2] && p1 < p2) {
        parent[p2] = p1;
        rank[p1] += rank[p1] == rank[p2];
    } else {
        parent[p1] = p2;
        rank[p2] += rank[p1] == rank[p2];
    }
    return true;
}

int getOther(pii &road, int &x) { return (road.sc.fs == x) ? road.sc.sc : road.sc.fs; }

void dfs(vector<int> &cities, vector<pii> &roads, vector<bool> &vis, vector<vector<int>> &adj, st<int> &stk) {
    cities[0] = INT32_MAX;
    stk.ps(0);
    int cur, other;
    while (!stk.empty()) {
        cur = stk.tp;
        stk.pp;
        if (vis[cur]) {
            continue;
        }
        vis[cur] = true;
        fora(i, 0, adj[cur].size(), 1) {
            other = getOther(roads[adj[cur][i]], cur);
            if (vis[other]) {
                continue;
            }
            cities[other] = min(roads[adj[cur][i]].fs, cities[cur]);
            stk.ps(other);
        }
    }
}

int main() {
    int numCities, numRoads, numDests, roadCount = 0, ans = INT32_MAX;
    vector<int> cities, cityParent, cityRank, dests;
    vector<vector<int>> adj; // Edge indices for adjacent nodes
    vector<pii> roads;       // (weight, {city1, city2})
    vector<bool> vis;
    st<int> stk;
    cin >> numCities >> numRoads >> numDests;
    cities.resize(numCities, 0), cityParent.resize(numCities), cityRank.resize(numCities), adj.resize(numCities),
        vis.resize(numCities, false);
    roads.resize(numRoads);
    dests.resize(numDests);
    fora(i, 0, numCities, 1) {
        cityParent[i] = i;
        cityRank[i] = 0;
    }
    fora(i, 0, numRoads, 1) {
        cin >> roads[i].sc.fs >> roads[i].sc.sc >> roads[i].fs;
        --roads[i].sc.fs;
        --roads[i].sc.sc;
    }
    fora(i, 0, numDests, 1) {
        cin >> dests[i];
        --dests[i];
    }
    sort(roads.begin(), roads.end(), greater<pii>());
    fora(i, 0, numRoads, 1) {
        if (join(cityParent, cityRank, stk, roads[i].sc.fs, roads[i].sc.sc)) {
            roadCount++;
            adj[roads[i].sc.fs].pb(i);
            adj[roads[i].sc.sc].pb(i);
        }
        if (roadCount == numCities - 1) {
            break;
        }
    }
    dfs(cities, roads, vis, adj, stk);
    fora(i, 0, numDests, 1) {
        ans = min(ans, cities[dests[i]]);
    }
    cout << ans << edl;
}