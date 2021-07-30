#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
#define x first
#define y second

char mp[1000][1001];

queue<ppi> q;
int main() {
    int mv[] = {1, 0, -1, 0, 0, -1, 0, 1};
    int n, m;
    scanf("%d%d%*c", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%c", &mp[i][j]);
            if (mp[i][j] == 's') {
                q.push({{i, j}, 0});
                mp[i][j] = 'X';
            }
        }
        scanf("%*c");
    }
    ppi c;
    while (!q.empty()) {
        c = q.front(); q.pop();
        for (int i = 0; i < 8; i += 2) {
            if (c.x.x + mv[i] >= 0 && c.x.x + mv[i] < n && c.x.y + mv[i + 1] >= 0 && c.x.y + mv[i + 1] < m && mp[c.x.x + mv[i]][c.x.y + mv[i + 1]] != 'X') {
                if (mp[c.x.x + mv[i]][c.x.y + mv[i + 1]] == 'e') {
                    printf("%d", c.y);
                    return 0;
                }
                mp[c.x.x + mv[i]][c.x.y + mv[i + 1]] = 'X';
                q.push({{c.x.x + mv[i], c.x.y + mv[i + 1]}, c.y + 1});
            }
        }
    }
    printf("-1");
    return 0;
}