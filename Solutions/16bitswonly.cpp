#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n;
    ll a, b, p;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &a, &b, &p);
        printf(((a * b != p) ? "16 BIT S/W ONLY\n" : "POSSIBLE DOUBLE SIGMA\n"));
    }
    return 0;
}