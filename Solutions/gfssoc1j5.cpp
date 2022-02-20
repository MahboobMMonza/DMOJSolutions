#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
#define f first
#define s second
struct R{vector<int> h; int d[1001] = {0};};
R r[1001];
int main() {
    int n, m, t, a, b, qr;
    scanf("%d%d%d", &n, &m, &t);
    while (m--) {
        scanf("%d%d", &a, &b);
        r[a].h.push_back(b);
    }
    queue<pii> q;
    pii x;
    for (int i = 1; i<= n; i++) {
        q.push({i, 0});
        while (!q.empty()) {
            x = q.front(); q.pop();
            for (int j = 0; j < r[x.f].h.size(); ++j) {
                if (!r[i].d[r[x.f].h[j]] && r[x.f].h[j] != i) {
                    r[i].d[r[x.f].h[j]] = x.s + 1;
                    q.push({r[x.f].h[j], x.s + 1});
                }
            }
        }
    }
    scanf("%d", &qr);
    while (qr--) {
        scanf("%d%d", &a, &b);
        if (a == b) printf("0\n");
        else (r[a].d[b]) ? printf("%d\n", r[a].d[b] * t) : printf("Not enough hallways!\n");
    }
    return 0;
}