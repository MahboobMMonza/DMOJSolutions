#include <bits/stdc++.h>

using namespace std;

char s[100001];

int main() {
    int n;long long ans = 1;
    scanf("%s", s);
    n = strlen(s);
    int f[26] = {};
    for (int i = 0; i < n; i++) {
        f[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        ans  = (ans * (f[i] + 1)) % (int) (1e9 + 7);
    }
    printf("%lld\n", ans);
    return 0;
}