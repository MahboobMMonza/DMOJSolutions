#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

pii tim[100001];

bool cmp(pii a, pii b) {
    return a.first < b.first;
};

int main() {
    int n, time, dist;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &time);
        scanf("%d", &dist);
        tim[i] = {time, dist};
    }
    sort(tim, tim+n, cmp);
    double cs, hs = 0;
    for (int i = 1; i < n; i++) {
        cs = abs((tim[i].second + 0.0 - tim[i - 1].second)/(tim[i].first + 0.0 - tim[i - 1].first));
        hs = max(hs, cs);
    }
    printf("%.6lf", hs);
    return 0;
}