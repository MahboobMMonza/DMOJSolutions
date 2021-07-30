#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, arr[] = {-1, 1, 2, 4, 7, 8, 11, 13, 14};
    scanf("%lld", &n);
    printf("%lld\n", (15 * (n / 8)) + arr[n % 8]);
    return 0;
}