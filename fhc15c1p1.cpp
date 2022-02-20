#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int sieve[(int) 1e7 + 10];

int main() {
    for (int i = 2; i <= (int) 1e7; i++) {
        if (sieve[i] == 0) {
            sieve[i] = 1;
            for (int j = i + i; j <= (int) 1e7; j += i) {
                sieve[j]++;
            }
        }
    }
    int t, a, b, k, c;
    scanf("%d", &t);
    for (int j = 1; j <= t; j++) {
        c = 0;
        scanf("%d%d%d", &a, &b, &k);
        for (int i = a; i <= b; i++) {
            c += (sieve[i] == k);
        }
        printf("Case #%d: %d\n", j, c);
    }
    return 0;
}