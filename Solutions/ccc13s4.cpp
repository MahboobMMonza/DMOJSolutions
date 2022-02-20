#include <bits/stdc++.h>

using namespace std;

unordered_set<int> t[1000001];
int main() {
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        t[a].insert(b);
    }
    scanf("%d%d", &a, &b);
    queue<int> q;
    q.push(a);
    t[0].insert(a);
    while (!q.empty()) {
        m = q.front(); q.pop();
        unordered_set<int>::iterator it;
        for (it = t[m].begin(); it != t[m].end(); it++) {
            if (!t[0].count(*it)) {
                if (*it == b) {
                    printf("yes");
                    return 0;
                } else {
                    q.push(*it);
                    t[0].insert(*it);
                }
            }
        }
    }
    t[0].clear();
    q.push(b);
    t[0].insert(b);
    while (!q.empty()) {
        m = q.front(); q.pop();
        unordered_set<int>::iterator it;
        for (it = t[m].begin(); it != t[m].end(); it++) {
            if (!t[0].count(*it)) {
                if (*it == a) {
                    printf("no");
                    return 0;
                } else {
                    q.push(*it);
                    t[0].insert(*it);
                }
            }
        }
    }
    printf("unknown");
    return 0;
}