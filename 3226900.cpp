#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k;
    scanf("%lld%lld", &n, &k);
    n = n % k;
    n = min(n, abs(n - k));
    printf("%lld", n);
    return 0;
}