#include <bits/stdc++.h>

using namespace std;

int v[1000001] = {0}, f[1000001] = {0};
deque<int> g, u;
int main() {
    int n, b;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b);
        if (!v[b]) {
            g.push_back(b);
            v[b] = 1;
            f[i] = 1;
        }
    }
    if (g.size() == 1) {
        printf("-1");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (!v[i]) u.push_back(i);
    }
    g.push_back(g.front());
    g.pop_front();
    for (int i = 1; i <= n; i++) {
        if (f[i]) {
            printf("%d ", g.front());
            g.pop_front();
        } else {
            printf("%d ", u.front());
            u.pop_front();
        }
    }
    return 0;
}