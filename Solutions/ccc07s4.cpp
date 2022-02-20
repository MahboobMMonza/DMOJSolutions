#include <bits/stdc++.h>

using namespace std;

list<int> adj[10000];
int d[10000] = {0};
int main() {
    int n, x, y;
    scanf("%d", &n);
    while (true) {
        scanf("%d%d", &x, &y);
        if (!(x + y)) break;
        adj[y].push_back(x);
    }
    while (!adj[n].empty()) {
        d[adj[n].front()] = 1;
        adj[n].pop_front();
    }
    for (int i = n - 1; i > 0; i--) {
        while (!adj[i].empty()) {
            d[adj[i].front()] += d[i];
            adj[i].pop_front();
        }
    }
    printf("%d", d[1]);
    return 0;
}