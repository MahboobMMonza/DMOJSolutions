#include <bits/stdc++.h>

using namespace std;
unordered_set<int> vis, st;
int ci[5001] = {0}, sp[5001] = {0}, e[5001][5001] = {0};

int main() {
    int n, t, x, y, c, k, d, mp = INT_MAX;
    scanf("%d%d", &n, &t);
    while (t--) {
        scanf("%d%d%d", &x, &y, &c);
        if (x && y && x <= n && y <= n) e[x][y] = e[y][x] = c;
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &x, &c);
        sp[x] = c;
        st.insert(x);
    }
    scanf("%d", &d);
    ci[d] = 0;
    x = d;
    while (!st.empty()) {
        if (vis.count(x)) {
            y = INT_MAX;
            for (int i = 1; i <= n; i++) {
                if (ci[i] && ci[i] < y && !vis.count(i)) {
                    y = ci[i];
                    x = i;
                } else if (ci[i] == y && !vis.count(i) && sp[i] < sp[x]) x = i;
            }
        }
        vis.insert(x);
        if (st.count(x)) {
            mp = min(mp, ci[x] + sp[x]);
        }
        st.erase(x);
        if (st.empty()) break;
        for (int i = 1; i <= n; i++) {
            if (e[x][i] && !vis.count(i)) {
                ci[i] = (ci[i]) ? min(ci[i], ci[x] + e[x][i]) : ci[x] + e[x][i];
            }
        }
    }
    printf("%d", mp);
    return 0;
}