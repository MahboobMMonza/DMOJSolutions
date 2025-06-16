#include <bits/stdc++.h>
#include <ext/typelist.h>

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
#define fora(i, a, b) for (int i = (a); i < (b); ++i)
#define forae(i, a, b) for (int i = (a); i <= (b); ++i)
#define foras(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define foraes(i, a, b, c) for (int i = (a); i <= (b); i += (c))
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define forde(i, a, b) for (int i = (a); i >= (b); --i)
#define fords(i, a, b, c) for (int i = (a); i > (b); i -= (c))
#define fordes(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
#define foral(i, a, b) for (long long i = (a); i < (b); i++)
#define forael(i, a, b) for (long long i = (a); i <= (b); i++)
#define fordl(i, a, b) for (long long i = (a); i > (b); i--)
#define fordel(i, a, b) for (long long i = (a); i >= (b); i--)
#define forals(i, a, b, c) for (long long i = (a); i < (b); i += (c))
#define foraels(i, a, b, c) for (long long i = (a); i <= (b); i += (c))
#define fordls(i, a, b, c) for (long long i = (a); i > (b); i -= (c))
#define fordels(i, a, b, c) for (long long i = (a); i >= (b); i -= (c))
#define foraz(i, a, b) for (size_t i = (a); i < (b); i++)
#define foraez(i, a, b) for (size_t i = (a); i <= (b); i++)
#define fordz(i, a, b) for (size_t i = (a); i > (b); i--)
#define fordez(i, a, b) for (size_t i = (a); i >= (b); i--)
#define forazs(i, a, b, c) for (size_t i = (a); i < (b); i += (c))
#define foraezs(i, a, b, c) for (size_t i = (a); i <= (b); i += (c))
#define fordzs(i, a, b, c) for (size_t i = (a); i > (b); i -= (c))
#define fordezs(i, a, b, c) for (size_t i = (a); i >= (b); i -= (c))
#define MOD (int) (1e9 + 7)

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
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
        if (y & 1) res = (res + x) % m;
        if (res < 0) res += m;
        x = (x << 1) % m;
        y >>= 1;
    }
    return res % m;
}

inline ll logPow(ll x, ll y, ll m = LONG_LONG_MAX) {
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

inline ll pLogPow(const ll x, const ll y, const ll m = 9223372036854775783) { return logPow(x, y % (m - 1), m); }

vector<size_t> bit_reversals(const size_t N) {
    vector<size_t> rev(N);
    size_t j = 0;
    rev[0] = 0;
    foraz(i, 1, N) {
        size_t bit = N >> 1;
        for (; j & bit; bit >>= 1) {
            j ^= bit;
        }
        j ^= bit;
        rev[i] = j;
    }
    return rev;
}

vector<complex<double> > twiddle(const size_t N) {
    vector<complex<double> > w_j(N);
    constexpr double TAU = 2 * acos(-1);
    foraz(i, 0, N) {
        w_j[i] = polar(1., TAU * static_cast<double>(i) / static_cast<double>(N));
    }
    return w_j;
}

void fft_inplace(vector<complex<double> > &p, const vector<size_t> &rev, const vector<complex<double> > &w_j) {
    const size_t N = p.size();
    foraz(i, 0, N) {
        if (i > rev[i]) continue;
        swap(p[i], p[rev[i]]);
    }
    forae(s, 1, __builtin_ctzll(N)) {
        const size_t window_size = 1 << s;
        const size_t half_window_size = window_size >> 1;
        const size_t ratio = N >> s;
        forazs(i, 0, N, window_size) {
            foraz(j, 0, window_size >> 1) {
                auto y_e = p[i + j], y_o = w_j[ratio * j] * p[i + j + half_window_size];
                p[i + j] = y_e + y_o;
                p[i + j + half_window_size] = y_e - y_o;
            }
        }
    }
}

size_t pad(const size_t N) {
    return 1ull << (64 - __builtin_clzll((N << 1) - 1));
}

string solve(const string &a, const string &b) {
    if (a == "0" || b == "0") {
        return "0";
    }
    ostringstream oss;
    const size_t SAMPLE_N = pad(max((a.size() + 3) / 4, (b.size() + 3) / 4));
    vector<complex<double> > p_a(SAMPLE_N), p_b(SAMPLE_N), p_c(SAMPLE_N);
    vector<ll> prod(SAMPLE_N);
    const auto w_j = twiddle(SAMPLE_N);
    const auto rev = bit_reversals(SAMPLE_N);
    int mult = 1;
    constexpr int BASE = 10000;
    for (size_t i = a.size() - 1; i < a.size(); i--) {
        const int v = a[i] - '0';
        p_a[(a.size() - 1 - i) / 4] += v * mult;
        mult *= 10;
        if (mult >= BASE) mult = 1;
    }
    mult = 1;
    for (size_t i = b.size() - 1; i < b.size(); i--) {
        const int v = b[i] - '0';
        p_b[(b.size() - 1 - i) / 4] += v * mult;
        mult *= 10;
        if (mult >= BASE) mult = 1;
    }
    fft_inplace(p_a, rev, w_j);
    fft_inplace(p_b, rev, w_j);
    // swap c_im and c_re
    foraz(i, 0, SAMPLE_N) {
        const auto res = p_a[i] * p_b[i];
        p_c[i].real(res.imag());
        p_c[i].imag(res.real());
    }
    fft_inplace(p_c, rev, w_j);
    ll carry = 0;
    foraz(i, 0, SAMPLE_N) {
        const ll sum = static_cast<ll>(round(p_c[i].imag() / SAMPLE_N)) + carry;
        carry = sum / BASE;
        prod[i] = sum % BASE;
    }
    if (carry) {
        oss << carry;
    }
    ll check = carry;
    for (size_t i = SAMPLE_N - 1; i < SAMPLE_N; i--) {
        bool zpad = check;
        check |= prod[i];
        if (!check) continue;
        if (zpad) oss << setfill('0') << setw(4);
        oss << prod[i];
    }
    return oss.str();
}

int main() {
    fio;
    string a, b;
    cin >> a >> b;
    auto solnB = solve(a, b);
    cout << solnB << edl;
    return 0;
}
