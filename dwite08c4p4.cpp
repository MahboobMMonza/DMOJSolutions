#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ip;
bool v[8][8] = {0};
queue<ip> q;
char mp[8][9];

int main() {
    pii st;
    int x, y;
    for (int t = 0; t < 5; t++) {
        for (int i = 0; i < 8; i++) {
            scanf("%s", mp[i]);
            for (int j = 0; j < 8; j++) {
                v[i][j] = 0;
                if (mp[i][j] == 'A') {
                    st = make_pair(i, j);
                }
            }
        }
        q.push(make_pair(st, 0));
        v[st.first][st.second] = 1;
        while (!q.empty()) {
            ip p = q.front();
            q.pop();
            x = p.first.first;
            y = p.first.second;
            if (mp[x][y] == 'B') {
                printf("%d\n", p.second);
                break;
            }
            if (x > 0) {
                if (y > 0) {
                    if (!v[x - 1][y - 1] && mp[x - 1][y - 1] != '#') {
                        v[x - 1][y - 1] = 1;
                        q.push(make_pair(make_pair(x - 1, y - 1), p.second + 1));
                    }
                }
                if (y < 7) {
                    if (!v[x - 1][y + 1] && mp[x - 1][y + 1] != '#') {
                        v[x - 1][y + 1] = 1;
                        q.push(make_pair(make_pair(x - 1, y + 1), p.second + 1));
                    }
                }
                if (!v[x - 1][y] && mp[x - 1][y] != '#') {
                    v[x - 1][y] = 1;
                    q.push(make_pair(make_pair(x - 1, y), p.second + 1));
                }
            }
            if (x < 7) {
                if (y > 0) {
                    if (!v[x + 1][y - 1] && mp[x + 1][y - 1] != '#') {
                        v[x + 1][y - 1] = 1;
                        q.push(make_pair(make_pair(x + 1, y - 1), p.second + 1));
                    }
                }
                if (y < 7) {
                    if (!v[x + 1][y + 1] && mp[x + 1][y + 1] != '#') {
                        v[x + 1][y + 1] = 1;
                        q.push(make_pair(make_pair(x + 1, y + 1), p.second + 1));
                    }
                }
                if (!v[x + 1][y] && mp[x + 1][y] != '#') {
                    v[x + 1][y] = 1;
                    q.push(make_pair(make_pair(x + 1, y), p.second + 1));
                }
            }
            if (y > 0 && !v[x][y - 1] && mp[x][y - 1] != '#') {
                v[x][y - 1] = 1;
                q.push(make_pair(make_pair(x, y - 1), p.second + 1));
            }
            if (y < 7 && !v[x][y + 1] && mp[x][y + 1] != '#') {
                v[x][y + 1] = 1;
                q.push(make_pair(make_pair(x, y + 1), p.second + 1));
            }
        }
        while (!q.empty()) {
            q.pop();
        }
    }
    return 0;
}