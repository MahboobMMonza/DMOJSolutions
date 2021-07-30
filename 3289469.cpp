#include <bits/stdc++.h>

using namespace std;

class p {
public:
    int n, d = INT_MAX;
    vector<int> a;
    p() = default;
    p(int n) {this->n = n;}
    int ud(int d) {
        this->d = min(this->d, d);
        return 0;
    }
    int ae(int x) {
        a.push_back(x);
        return 0;
    }
};

unordered_set<int> vis;
p b[10001];
queue<int> q;
int main() {
    int n, m, e, md = INT_MAX;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        b[i] = p(i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &e);
            b[i].ae(e);
        }
    }
    q.push(1);
    b[1].ud(1);
    while (!q.empty()) {
        e = q.front(); q.pop();
        vis.insert(e);
        if (b[e].a.size() == 0) {
            md = min(b[e].d, md);
            continue;
        }
        vector<int>::iterator it;
        for (it = b[e].a.begin(); it != b[e].a.end(); it++) {
            if (!vis.count(*it)) {
                b[*it].ud(b[e].d + 1);
                q.push(*it);
            }
        }
    }
    printf("%c\n", (vis.size() == n) ? 'Y' : 'N');
    printf("%d", md);
    return 0;
}