#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
#define x first
#define y second

char mp[1000][1001];
int d[1000][1000] = {0}, md[2][1000][1000] = {0};
queue<pii> q;
int main() {
    int g, r, c;
    int mv[] = {-1, 0, 1, 0, 0, -1, 0, 1};
    pii m1, m2, e, s, w;
    scanf("%d", &g);
    while (g--) {
        scanf("%d%d%*c", &r, &c);
        m1 = {-1, -1};
        m2 = {-1, -1};
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%c", &mp[i][j]);
                d[i][j] = -1;
                md[0][i][j] = md[1][i][j] = -1;
                if (mp[i][j] == 'P') {
                    d[i][j] = 0;
                    s = {i, j};
                }
                if (mp[i][j] == 'C') e = {i, j};
                if (mp[i][j] == 'M') {
                    if (m1.x == -1) {
                        m1 = {i, j};
                        md[0][i][j] = 0;
                    } else {
                        m2 = {i, j};
                        md[1][i][j] = 0;
                    }
                }
            }
            scanf("%*c");
        }
        while (!q.empty()) q.pop();
        q.push(m1);
        while (!q.empty()) {
            w = q.front(); q.pop();
            for (int i = 0; i < 8; i += 2) {
                if (w.x + mv[i] >= 0 && w.x + mv[i] < r && w.y + mv[i + 1] >= 0 && w.y + mv[i + 1] < c && md[0][w.x + mv[i]][w.y + mv[i + 1]] == -1 && mp[w.x + mv[i]][w.y + mv[i + 1]] != 'M' && mp[w.x + mv[i]][w.y + mv[i + 1]] != 'W') {
                        md[0][w.x + mv[i]][w.y + mv[i + 1]] = md[0][w.x][w.y] + 1;
                        q.push({w.x + mv[i], w.y + mv[i + 1]});

                }
            }
        }
        q.push(m2);
        while (!q.empty()) {
            w = q.front(); q.pop();
            for (int i = 0; i < 8; i += 2) {
                if (w.x + mv[i] >= 0 && w.x + mv[i] < r && w.y + mv[i + 1] >= 0 && w.y + mv[i + 1] < c && md[1][w.x + mv[i]][w.y + mv[i + 1]] == -1 && mp[w.x + mv[i]][w.y + mv[i + 1]] != 'M' && mp[w.x + mv[i]][w.y + mv[i + 1]] != 'W') {
                        md[1][w.x + mv[i]][w.y + mv[i + 1]] = md[1][w.x][w.y] + 1;
                        q.push({w.x + mv[i], w.y + mv[i + 1]});
                }
            }
        }
        q.push(s);
        while (!q.empty()) {
            w = q.front(); q.pop();
            for (int i = 0; i < 8; i += 2) {
                if (w.x + mv[i] >= 0 && w.x + mv[i] < r && w.y + mv[i + 1] >= 0 && w.y + mv[i + 1] < c && mp[w.x + mv[i]][w.y + mv[i + 1]] != 'M' && mp[w.x + mv[i]][w.y + mv[i + 1]] != 'W' && d[w.x + mv[i]][w.y + mv[i + 1]] == -1) {
                    bool f = 1;
                    if (mp[w.x][w.y] == 'U' || mp[w.x + mv[i]][w.y + mv[i + 1]] == 'U') {
                        f = (md[0][w.x + mv[i]][w.y + mv[i + 1]] < md[0][w.x][w.y] || md[1][w.x + mv[i]][w.y + mv[i + 1]] < md[1][w.x][w.y]);
                    }
                    if (f) {
                        d[w.x + mv[i]][w.y + mv[i + 1]] = d[w.x][w.y] + 1;
                        q.push({w.x + mv[i], w.y + mv[i + 1]});
                    }
                }
            }
        }
        (d[e.x][e.y] != -1) ? printf("pwned you in %d seconds eZ, learn to play n00b\n", d[e.x][e.y]) : printf("terran so broken, apologize for playing this race\n");
    }
    return 0;
}