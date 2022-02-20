#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    ll k;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%lld", &k);
        k++;
        for (; (k * k * k) % 1000 != 888; k++) {
            
        }
        printf("%lld\n", k);
    }
    return 0;
}