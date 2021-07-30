#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
#define x first
#define y second

int d[100][100] = {0};
char mp[100][101];
vector<pii> poi, cm;
queue<pii> q;

int cctv(pii p, int n, int m) {
    int r = p.x, c = p.y;
    while (mp[r][c] != 'W' && c < m) {
        if (mp[r][c] == 'S' || mp[r][c] == '.') d[r][c]--;
        c++;
    }
    c = p.y;
    while (mp[r][c] != 'W' && c >= 0) {
        if (mp[r][c] == 'S' || mp[r][c] == '.') d[r][c]--;
        c--;
    }
    c = p.y;
    while (mp[r][c] != 'W' && r >= 0) {
        if (mp[r][c] == 'S' || mp[r][c] == '.') d[r][c]--;
        r--;
    }
    r = p.x;
    while (mp[r][c] != 'W' && r < n) {
        if (mp[r][c] == 'S' || mp[r][c] == '.') d[r][c]--;
        r++;
    }
    return 0;
}

int main() {
    int n, m, mv[] = {1, 0, -1, 0, 0, 1, 0, -1}, r, c;
    pii a;
    scanf("%d%*c%d%*c", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", mp[i]);
        for (int j = 0; j < m; j++) {
            d[i][j] = -1;
            if (mp[i][j] == 'S') {
                q.push({i, j});
                d[i][j] = 0;
            }
            if (mp[i][j] == '.') {
                poi.emplace_back(i, j);
            }
            if (mp[i][j] == 'C') {
                cm.emplace_back(i, j);
                d[i][j] = -2;
            }
            if (mp[i][j] == 'W') d[i][j] = -2;
        }
    }
    for (auto p : cm) {
        cctv(p, n, m);
    }
    if (d[q.front().x][q.front().y] == -1) {
        for (int i = 0; i < poi.size(); i++) {
            printf("-1\n");
        }
        return 0;
    }
    while (!q.empty()) {
        a = q.front();
        q.pop();
        if (mp[a.x][a.y] != 'S' && mp[a.x][a.y] != '.') {
            if (mp[a.x][a.y] == 'U' && a.x - 1 >= 0 && (d[a.x - 1][a.y] == -1 || d[a.x - 1][a.y] > d[a.x][a.y] + 1)) {
                if (mp[a.x - 1][a.y] == '.') {
                    d[a.x - 1][a.y] = d[a.x][a.y] + 1;
                    q.push({a.x - 1, a.y});
                } else if (mp[a.x - 1][a.y] != 'D') {
                    d[a.x - 1][a.y] = d[a.x][a.y];
                    q.push({a.x - 1, a.y});
                }
            } else if (mp[a.x][a.y] == 'D' && a.x + 1 < n &&
                       (d[a.x + 1][a.y] == -1 || d[a.x + 1][a.y] > d[a.x][a.y] + 1)) {
                if (mp[a.x + 1][a.y] == '.') {
                    d[a.x + 1][a.y] = d[a.x][a.y] + 1;
                    q.push({a.x + 1, a.y});
                } else if (mp[a.x + 1][a.y] != 'U') {
                    d[a.x + 1][a.y] = d[a.x][a.y];
                    q.push({a.x + 1, a.y});
                }
            } else if (mp[a.x][a.y] == 'L' && a.y - 1 >= 0 &&
                       (d[a.x][a.y - 1] == -1 || d[a.x][a.y - 1] > d[a.x][a.y] + 1)) {
                if (mp[a.x][a.y - 1] == '.') {
                    d[a.x][a.y - 1] = d[a.x][a.y] + 1;
                    q.push({a.x, a.y - 1});
                } else if (mp[a.x][a.y - 1] != 'R') {
                    d[a.x][a.y - 1] = d[a.x][a.y];
                    q.push({a.x, a.y - 1});
                }
            } else if (mp[a.x][a.y] == 'R' && a.y + 1 < m &&
                       (d[a.x][a.y + 1] == -1 || d[a.x][a.y + 1] > d[a.x][a.y] + 1)) {
                if (mp[a.x][a.y + 1] == '.') {
                    d[a.x][a.y + 1] = d[a.x][a.y] + 1;
                    q.push({a.x, a.y + 1});
                } else if (mp[a.x][a.y + 1] != 'L') {
                    d[a.x][a.y + 1] = d[a.x][a.y];
                    q.push({a.x, a.y + 1});
                }
            }
            continue;
        }
        for (int i = 0; i < 8; i += 2) {
            r = a.x + mv[i];
            c = a.y + mv[i + 1];
            if (r >= 0 && r < n && c >= 0 && c < m && (d[r][c] == -1 || d[r][c] > d[a.x][a.y] + 1 || (mp[r][c] != '.' && d[r][c] > d[a.x][a.y]))) {
                if (mp[r][c] == 'U' && r - 1 >= 0 && mp[r - 1][c] != 'D') {
                    d[r][c] = d[a.x][a.y];
                    q.push({r, c});
                } else if (mp[r][c] == 'D' && r + 1 < n && mp[r + 1][c] != 'U') {
                    d[r][c] = d[a.x][a.y];
                    q.push({r, c});
                } else if (mp[r][c] == 'L' && c - 1 >= 0 && mp[r][c - 1] != 'R') {
                    d[r][c] = d[a.x][a.y];
                    q.push({r, c});
                } else if (mp[r][c] == 'R' && c + 1 < m && mp[r][c + 1] != 'L') {
                    d[r][c] = d[a.x][a.y];
                    q.push({r, c});
                } else {
                    d[r][c] = d[a.x][a.y] + 1;
                    q.push({r, c});
                }
            }
        }
    }
    for (auto p : poi) {
        (d[p.x][p.y] >= 0) ? printf("%d\n", d[p.x][p.y]) : printf("-1\n");
    }
    return 0;
}