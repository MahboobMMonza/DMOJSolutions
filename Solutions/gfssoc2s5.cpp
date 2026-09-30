#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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
#define fora(i, a, b) for (int i = (a); i < (b); ++i)
#define forae(i, a, b) for (int i = (a); i <= (b); ++i)
#define foras(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define foraes(i, a, b, c) for (int i = (a); i <= (b); i += (c))
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define forde(i, a, b) for (int i = (a); i >= (b); --i)
#define fords(i, a, b, c) for (int i = (a); i > (b); i -= (c))
#define fordes(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
#define forals(i, a, b, c) for (long long i = (a); i < (b); i += (c))
#define foraels(i, a, b, c) for (long long i = (a); i <= (b); i += (c))
#define fordls(i, a, b, c) for (long long i = (a); i > (b); i -= (c))
#define fordels(i, a, b, c) for (long long i = (a); i >= (b); i -= (c))
#define foraz(i, a, b) for (size_t i = (a); i < (b); ++i)
#define foraez(i, a, b) for (size_t i = (a); i <= (b); ++i)
#define fordz(i, a, b) for (size_t i = (a); i > (b); --i)
#define fordez(i, a, b) for (size_t i = (a); i >= (b); --i)
#define ford0z(i, a, b) for (size_t i = (a); i < (b); --i)
#define forazs(i, a, b, c) for (size_t i = (a); i < (b); i += (c))
#define foraezs(i, a, b, c) for (size_t i = (a); i <= (b); i += (c))
#define fordzs(i, a, b, c) for (size_t i = (a); i > (b); i -= (c))
#define fordezs(i, a, b, c) for (size_t i = (a); i >= (b); i -= (c))
#define ford0zs(i, a, b, c) for (size_t i = (a); i < (b); i -= (c))
#define MOD (int) (1e9 + 7)

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<size_t, size_t> pz;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pl;
typedef pair<ull, ull> pull;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;
typedef pair<pi, pi> ppi;
typedef pair<char, int> pci;

inline ll mulMod(ll x, ll y, ll m = numeric_limits<ll>::max()) {
    x %= m;
    ll res = 0;
    while (y) {
        if (y & 1) res = (res + x) % m;
        if (res < 0) res += m;
        x = (x << 1) % m;
        y >>= 1;
    }
    return res % m;
}

inline ll logPow(ll x, ll y, ll m = numeric_limits<ll>::max()) {
    x %= m;
    ll res = 1;
    while (y) {
        if (y & 1) res = mulMod(res, x, m);
        x = mulMod(x, x, m);
        y >>= 1;
    }
    return res % m;
}

inline ll fsLogPow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

inline ll pLogPow(ll x, ll y, ll m = 9223372036854775783) { return logPow(x, y % (m - 1), m); }

struct custom_hash {
    static ull splitmix64(ull x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    ull operator()(ull x) const {
        static const ull FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    size_t operator()(const pz &x) const {
        static const size_t FIXED_RANDOM = static_cast<size_t>(chrono::steady_clock::now().time_since_epoch().count());
        auto packed = (static_cast<ull>(x.fs) << 32) | static_cast<ull>(x.sc);
        return splitmix64(packed + FIXED_RANDOM);
    }
};

template<typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using indexed_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename Derived, typename T>
class ISegNode {
public:
    static Derived create(const T& val) {
        return Derived::create_impl(val);
    }

    static Derived op(const Derived &l, const Derived &r) {
        return Derived::op_impl(l, r);
    }
};

template<typename T, T neutral>
class SegNode : public ISegNode<SegNode<T, neutral>, T> {
public:
    T val;

    SegNode() : val(neutral) {}
    SegNode(T value) : val(value) {}

    static SegNode create_impl(T val) {
        return SegNode(val);
    }

    static SegNode op_impl(const SegNode &l, const SegNode &r) {
        return SegNode(l.val + r.val);
    }
};

template<typename T, typename D>
class SegmentTree {
private:
    vector<D> rangeData;
    size_t sz;

public:
    SegmentTree(const vector<T> &data) {
        rangeData.resize(2 * data.size());
        rangeData[0] = D();
        sz = data.size();
        for (size_t i = 0; i < sz; i++) {
            rangeData[sz + i] = D::create(data[i]);
        }
        for (size_t i = sz - 1; i > 0; --i) {
            rangeData[i] = D::op(rangeData[2 * i], rangeData[2 * i + 1]);
        }
    }

    SegmentTree(const size_t &n) : sz(n) {
        rangeData.resize(2 * n);
    }

    void update(size_t i, const T& value) {
        i += sz;
        rangeData[i] = D::create(value);
        while (i >>= 1) {
            rangeData[i] = D::op(rangeData[2 * i], rangeData[2 * i + 1]);
        }
    }

    D queryRange(size_t l, size_t r) {
        // EXCLUSIVE OF r
        l += sz, r += sz;
        D left, right;
        bool lefted = false, righted = false;
        while (l < r) {
            if (l&1) {
                if (!lefted) {
                    left = rangeData[l];
                    lefted = true;
                } else {
                    left = D::op(left, rangeData[l]);
                }
                l++;
            }
            if (r&1) {
                --r;
                if (!righted) {
                    righted = true;
                    right = rangeData[r];
                } else {
                    right = D::op(rangeData[r], right); 
                }
            }
            l >>= 1, r >>= 1;
        }
        if (!lefted) return right;
        if (!righted) return left;
        return D::op(left, right);
    }

};

typedef SegNode<int, 0> iadd_node;

template<typename T, typename = typename enable_if<is_arithmetic<T>::value>::type>
struct Vec2D {
    T x{}, y{};

    Vec2D() {}

    Vec2D(T x_val, T y_val) : x(x_val), y(y_val) {}

    Vec2D(const array<pair<T, T>, 2> &coords) : Vec2D(coords[0], coords[1]) {}

    Vec2D(const pair<T, T> &anchor, const pair<T, T> &tip) {
        x = tip.fs - anchor.fs;
        y = tip.sc - anchor.sc;
    }

    T norm() const {
        return x * x + y * y;
    }

    T operator^(const Vec2D &other) const {
        return (x * other.y) - (other.x * y);
    }

    Vec2D operator*(const T& k) const {
        return Vec2D(k * x, k * y);
    }

    Vec2D operator+(const Vec2D &other) const {
        return Vec2D(x + other.x, y + other.y);
    }

    Vec2D operator-(const Vec2D &other) const {
        return Vec2D(x - other.x, y - other.y);
    }

    Vec2D operator-() const {
        return Vec2D(-x, -y);
    }
};

class BitVector {
public:
    explicit BitVector(const size_t n) : v((n + 63) >> 6, 0) {
    };

    ~BitVector() = default;

    bool get(const size_t i) const {
        return v[i >> 6] & (1ull << (i & 63));
    }

    void set(const size_t i) {
        v[i >> 6] |= 1ull << (i & 63);
    }

    void clear(const size_t i) {
        v[i >> 6] &= ~(1ull << (i & 63));
    }

    void toggle(const size_t i) {
        v[i >> 6] ^= 1ull << (i & 63);
    }

    static string to_string(const BitVector &bv) {
        ostringstream ss;
        for (const auto &x: bv.v) {
            bitset<64> bits(x);
            string seq = bits.to_string();
            reverse(seq.begin(), seq.end());
            ss << seq;
        }
        return ss.str();
    }

private:
    vector<ull> v;
};

typedef struct edge {
    size_t to;
    size_t nxt;

    edge() = default;

    edge(const size_t to, const size_t nxt) : to(to), nxt(nxt) {}
} edge;

enum class Stage {
    COMPLETE,
    VISIT
};

void forwardDFS(const size_t a, const vector<size_t> &heads, const vector<edge> &edges, BitVector &vis, st<size_t> &order) {
    st<pair<size_t, Stage>> calls;
    calls.emplace(a, Stage::VISIT);
    while (!calls.empty()) {
        auto [cur, com] = calls.tp;
        calls.pp;
        if (com == Stage::COMPLETE) {
            order.ps(cur);
            continue;
        }
        if (vis.get(cur)) continue;
        vis.set(cur);
        calls.emplace(cur, Stage::COMPLETE);
        for (size_t i = heads[cur]; i < edges.size(); i = edges[i].nxt) {
            auto nbr = edges[i].to;
            if (vis.get(nbr)) continue;
            calls.emplace(nbr, Stage::VISIT);
        }
    }
}

void reverseDFS(const size_t a, const size_t idx, const vector<size_t> &heads, const vector<edge> &edges, BitVector &vis, vector<size_t> &comp) {
    st<size_t> calls;
    vis.set(a);
    calls.ps(a);
    while (!calls.empty()) {
        const auto cur = calls.tp;
        comp[cur] = idx;
        calls.pp;
        for (size_t i = heads[cur]; i < edges.size(); i = edges[i].nxt) {
            auto nbr = edges[i].to;
            if (vis.get(nbr)) continue;
            vis.set(nbr);
            calls.ps(nbr);
        }
    }
}

int main() {
    fio;
    /**
     * Get the SCCs, then do DP on the generated DAG in reverse topological order, settting last nodes's
     * component values as base case (ways[0][C_N] = ways[1][C_N] = 1) and set loot accordingly. Some'
     * components may not have a path to the last node's component, in which case ignore them.
     *
     * === DP TRANSITION ===
     * There is a DP transition for taking and skipping the current node
     * 0 is skip state, 1 is take state
     *
     * Take: dp[1][cur] = max(dp[1][cur], prov_loot[cur] + dp[0][nbr]
     *       Max between the current max and adding this component's loot to the best from skipping next component
     * Skip: dp[0][cur] = max(dp[0][cur], max(dp[1][nbr], dp[0][nbr]))
     *       Take max of skipping or taking the neighbour, and update the max for skipping here
     *
     * To count the number of ways, add to the ways tracker for the current state if the take/skip totals match.
     * When counting the skip, check for both taking AND skipping the neighbour node.
     *
     * The traveral order of this graph is reverse topological, so all neighbours will be already computed children
     * of the current component being processed.
     */
    static constexpr size_t Z = numeric_limits<size_t>::max();
    static constexpr ll MM = MOD, MIN_LL = numeric_limits<ll>::min();
    size_t N, M, prov_id = 0;
    cin >> N >> M;
    vector<size_t> heads(N, M), rev_heads(N, M), provinces(N), prov_heads, topsort;
    vector<edge> roads(M), rev_roads(M), prov_roads;
    vector<ll> loot(N), prov_loot;
    st<size_t> order;
    BitVector vis(N), rev_vis(N);
    foraz(i, 0, N) {
        cin >> loot[i];
    }
    foraz(i, 0, M) {
        size_t u, v;
        cin >> u >> v;
        u--, v--;
        roads[i].to = v;
        roads[i].nxt = heads[u];
        heads[u] = i;
        rev_roads[i].to = u;
        rev_roads[i].nxt = rev_heads[v];
        rev_heads[v] = i;
    }
    // Kosaraju's
    foraz(i, 0, N) {
        if (vis.get(i)) continue;
        forwardDFS(i, heads, roads, vis, order);
    }
    while (!order.empty()) {
        const auto cur = order.tp;
        order.pp;
        if (rev_vis.get(cur)) continue;
        topsort.pb(prov_id);
        reverseDFS(cur, prov_id++, rev_heads, rev_roads, rev_vis, provinces);
    }
    unordered_set<pz, custom_hash> prov_road_set;
    prov_loot.resize(prov_id, 0);
    prov_heads.resize(prov_id, Z);
    foraz(i, 0, N) {
        const auto cur_prov = provinces[i];
        prov_loot[provinces[i]] += loot[i];
        for (auto idx = heads[i]; idx < M; idx = roads[idx].nxt) {
            const auto& rd = roads[idx];
            const auto &nbr_prov = provinces[rd.to];
            if (nbr_prov == cur_prov) continue;
            const auto connection = make_pair(cur_prov, nbr_prov);
            const auto [_, res] = prov_road_set.insert(connection);
            if (!res) continue;
            prov_roads.eb(nbr_prov, prov_heads[cur_prov]);
            prov_heads[cur_prov] = prov_roads.size() - 1;
        }
    }
    // 0 -> don't borrow here | 1 -> borrow here
    vector<vector<ll>> dp(2, vector<ll>(prov_id, MIN_LL));
    vector<vector<ll>> ways(2, vector<ll>(prov_id, 0));
    dp[1][provinces.back()] = prov_loot[provinces.back()];
    dp[0][provinces.back()] = 0;
    ways[1][provinces.back()] = 1;
    ways[0][provinces.back()] = 1;
    ford0z(i, prov_id - 1, prov_id) {
        const auto &u = topsort[i];
        const auto take = prov_loot[u];
        for (auto idx = prov_heads[u]; idx < prov_roads.size(); idx = prov_roads[idx].nxt) {
            const auto& v = prov_roads[idx].to;
            // Take here
            dp[1][u] = max(take + dp[0][v], dp[1][u]);
            // Don't take from here, take from v or child of v
            dp[0][u] = max(dp[0][u], max(dp[1][v], dp[0][v]));
        }
        for (auto idx = prov_heads[u]; idx < prov_roads.size(); idx = prov_roads[idx].nxt) {
            const auto& v = prov_roads[idx].to;
            // Take from child
            if (dp[1][v] == dp[0][u]) {
                ways[0][u] = (ways[0][u] + ways[1][v]) % MM;
            }
            // Take from neither
            if (dp[0][u] == dp[0][v]) {
                ways[0][u] = (ways[0][u] + ways[0][v]) % MM;
            }
            // Take here
            if (take + dp[0][v] == dp[1][u]) {
                ways[1][u] = (ways[1][u] + ways[0][v]) % MM;
            }
        }
    }
    auto w = ways[0][provinces.front()];
    auto ans = max(dp[0][provinces.front()], dp[1][provinces.front()]);
    if (dp[1][provinces.front()] == ans) {
        w = ways[1][provinces.front()];
        if (dp[0][provinces.front()] == ans) {
            w = (w + ways[0][provinces.front()]) % MM;
        }
    }
    cout << ans << ' ' << w << edl;
    return 0;
}