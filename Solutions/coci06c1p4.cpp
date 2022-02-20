#include <bits/stdc++.h>

using namespace std;
#define x first
#define y second
typedef pair<int,int> pii;
char mp[50][51];
int d[2][50][50] = {0};
vector<pii> fl;
queue<pii> q;
int main() {
    int r, c, mv[] = {1, 0, -1, 0, 0, 1, 0, -1}, nx, ny;
    pii s, t;
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", mp[i]);
        for (int j = 0; j < c; j++) {
            d[0][i][j] = d[1][i][j] = INT_MAX;
            if (mp[i][j] == 'S') {
                s = {i, j};
                mp[i][j] = '.';
                d[1][i][j] = 0;
            }
            if (mp[i][j] == '*') {
                fl.emplace_back(i, j);
                d[0][i][j] = 0;
            }
        }
    }
    for (pii f : fl) {
        q.push(f);
        while (!q.empty()) {
            t = q.front();
            q.pop();
            for (int i = 0; i < 8; i += 2) {
                nx = t.x + mv[i];
                ny = t.y + mv[i + 1];
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && d[0][t.x][t.y] + 1 < d[0][nx][ny] && mp[nx][ny] == '.') {
                    d[0][nx][ny] = d[0][t.x][t.y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    q.push(s);
    while (!q.empty()) {
        t = q.front(); q.pop();
        if (mp[t.x][t.y] == 'D') {
            printf("%d\n", d[1][t.x][t.y]);
            return 0;
        }
        for (int i = 0; i < 8; i += 2) {
            nx = t.x + mv[i];
            ny = t.y + mv[i + 1];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && d[1][t.x][t.y] + 1 < d[1][nx][ny] && mp[nx][ny] != 'X' && d[0][nx][ny] > d[1][t.x][t.y] + 1) {
                d[1][nx][ny] = d[1][t.x][t.y] + 1;
                q.push({nx, ny});
            }
        }
    }
    printf("KAKTUS\n");
    return 0;
}