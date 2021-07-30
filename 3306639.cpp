#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef pair<int, int> pii;

class bd {
public:
    vector<pii> adj;
    int c = -1;

    void uc(int tc) {
        this->c = (this->c == -1) ? tc : min(this->c, tc);
    }

} w[500001];

bitset<500001> vis;


priority_queue<pii, vector<pii>, greater<pii>> pq;
int gg[2001] = {0};

int main() {
    int t, n, m, g, a, b, l, c = 0;
    pii x;
    scanf("%d%d%d%d", &t, &n, &m, &g);
    for (int i = 0; i < g; i++) {
        scanf("%d", &gg[i]);
    }
    while (m--) {
        scanf("%d%d%d", &a, &b, &l);
        w[a].adj.emplace_back(b, l);
    }
    w[0].uc(0);
    pq.push({0, 0});
    while (!pq.empty()) {
        x = pq.top();
        pq.pop();
        if (vis[x.s]) continue;
        vis[x.s] = 1;
        for (auto &p : w[x.s].adj) {
            if (!vis[p.f]) {
                w[p.f].uc(w[x.s].c + p.s);
                pq.push({w[p.f].c, p.f});

            }
        }
    }
    for (int i = 0; i < g; i++) {
        if (w[gg[i]].c < t && w[gg[i]].c != -1) {
            c++;
        }
    }
    setbuf(stdout, 0);
    printf("%d\n", c);
    return 0;
}