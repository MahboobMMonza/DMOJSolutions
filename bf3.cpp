#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool prime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (!(n % 2) || !(n % 3)) return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (!(n % i) || !(n % (i + 2))) return false;
    }
    return true;
}

int main() {
    ll n;
    scanf("%lld", &n);
    if (n == 1 || n == 2) {
        printf("2");
        return 0;
    }
    if (!(n % 2)) n++;
    while (!prime(n)) {
        n += 2;
    }
    printf("%lld", n);
}