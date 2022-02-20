#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> pp;
bool vis[20][20] = {0};
char m[20][21];
queue<pp> q;

int checkLat(pp a, int r, int c) {
    if (a.first.first > 0) {
        if (!vis[a.first.first - 1][a.first.second]) {
            if (m[a.first.first - 1][a.first.second] != '*') {
                q.push({{a.first.first - 1, a.first.second}, a.second + 1});
                vis[a.first.first - 1][a.first.second] = 1;
            }
        }
    }
    if (a.first.first + 1 < r) {
        if (!vis[a.first.first + 1][a.first.second]) {
            if (m[a.first.first + 1][a.first.second] != '*') {
                q.push({{a.first.first + 1, a.first.second}, a.second + 1});
                vis[a.first.first + 1][a.first.second] = 1;
            }
        }
    }
    return 0;
}

int checkLon(pp a, int r, int c) {
    if (a.first.second > 0) {
        if (!vis[a.first.first][a.first.second - 1]) {
            if (m[a.first.first][a.first.second - 1] != '*') {
                q.push({{a.first.first, a.first.second - 1}, a.second + 1});
                vis[a.first.first][a.first.second - 1] = 1;
            }
        }
    }
    if (a.first.second + 1 < c) {
        if (!vis[a.first.first][a.first.second + 1]) {
            if (m[a.first.first][a.first.second + 1] != '*') {
                q.push({{a.first.first, a.first.second + 1}, a.second + 1});
                vis[a.first.first][a.first.second + 1] = 1;
            }
        }
    }
    return 0;
}

int main() {
    int r, c, t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &r, &c);
        for (int i = 0; i < r; i++) {
            scanf("%s", m[i]);
            for (int j = 0; j < c; j++) vis[i][j] = 0;
        }
        q.push({{0, 0}, 1});
        vis[0][0] = 1;
        pp p;
        bool f = 0;
        while (!q.empty()) {
            p = q.front(); q.pop();
            char ch = m[p.first.first][p.first.second];
            if (p.first.first == r - 1 && p.first.second == c - 1) {
                printf("%d\n", p.second);
                f = 1;
                break;
            }
            if (ch == '|' || ch == '+') {
                checkLat(p, r, c);
            }
            if (ch == '+' || ch == '-') {
                checkLon(p, r, c);
            }
        }
        while (!q.empty()) q.pop();
        if (!f) printf("-1\n");
    }
    return 0;
}