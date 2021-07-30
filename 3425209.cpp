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
typedef uint64_t u64;
typedef __uint128_t u128;

u64 binPower(u64 base, u64 x, u64 mod) {
    u64 res = 1;
    base %= mod;
    while (x) {
        if (x & 1)
            res = (u128)res * base % mod;
        base = (u128)base * base % mod;
        x >>= 1;
    }
    return res;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binPower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1) return false;
    }
    return true;
}

bool MillerRabin(u64 n) {
    if (n < 2) return 0;
    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 13, 29, 31, 37}) {
        if (n == a) return 1;
        if (check_composite(n, a, d, r)) return 0;
    }
    return true;
}

int main() {
    u64 n;
    scanf("%lld", &n);
    if (n <= 2) {
        printf("2");
        return 0;
    }
    if (!(n & 1)) n++;
    while (!MillerRabin(n)) {
        n += 2;
        if (n != 5 && !(n % 5)) n += 2;
    }
    printf("%lld", n);
    return 0;
}