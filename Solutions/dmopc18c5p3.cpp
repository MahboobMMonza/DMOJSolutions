#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll s[200001] = {0};
int main() {
    int n, c = 0, l = 0, r = 1;
    ll m;
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &s[i]);
        s[i] += s[i - 1];
    }
    while(r <= n) {
        if (s[r] - s[l] < m) {
            c = max(c, r - l);
            r++;
        } else l++;
    }
    printf("%d", c);
    return 0;
}