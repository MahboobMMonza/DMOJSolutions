#include <bits/stdc++.h>

using namespace std;

#define x first
#define s second

typedef pair<int, int> pi;

bool cmp(pi const& a, pi const& b) {
    return a.s > b.s;
}

int main() {
    unordered_map<int, int> f; 
    int n, w;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &w);
        f[w]++;
    }
    vector<pi> fp (f.begin(), f.end());
    sort(fp.begin(), fp.end(), cmp);
    printf("%d", fp[0].s + fp[1].s);
    return 0;
}