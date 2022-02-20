#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll PRIME = 13457986268975431, BASE = 26;
char n[200001], h[200001];
int fn[26] = {0}, fh[26] = {0};
unordered_set<ll> has;

int match() {
    for (int i = 0; i < 26; i++) {
        if (fn[i] != fh[i]) return 0;
    }
    return 1;
}

int main() {
    scanf("%s%s", n, h);
    const ll POWER = strlen(n) - 1;
    ll hs = 0, mx = 1;
    for (int i = 0; i < POWER; i++) {
        mx = (mx * BASE) % PRIME;
    }
    if (strlen(n) > strlen(h)) {
        printf("0");
        return 0;
    }
    for (int i = 0; i < strlen(n); i++) {
        fn[n[i] - 'a']++;
        fh[h[i] - 'a']++;
        hs = (hs * BASE + (h[i] - 'a' + 1)) % PRIME;
    }
    if (match()) {
        has.insert(hs);
    }
    for (int i = 1; i <= strlen(h) - strlen(n); i++) {
        fh[h[i - 1] - 'a']--;
        fh[h[i + POWER] - 'a']++;
        hs = (BASE * (hs - ((h[i - 1] - 'a' + 1) * mx)) + (h[i + POWER] - 'a' + 1)) % PRIME;
        if (hs < 0) {
            hs = hs + PRIME;
        }
        if (match()) {
            has.insert(hs);
        }
    }
    printf("%d", has.size());
    return 0;
}