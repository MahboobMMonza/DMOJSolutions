#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ip;
bool v[10][10] = {0};
queue<ip> q;
char mp[10][10];

int main() {
    bool s;
    pii st;
    int x, y;
    for (int t = 0; t < 5; t++) {
        s = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                scanf("%c", &mp[i][j]);
                v[i][j] = 0;
                if (!s && mp[i][j] == 'X') {
                    st = make_pair(i, j);
                    mp[i][j] = 'S';
                    s = 1;
                }
            }
            scanf("%*c");
        }
        scanf("%*s%*c");
        q.push(make_pair(st, 0));
        v[st.first][st.second] = 1;
        while (!q.empty()) {
            ip p = q.front();
            q.pop();
            x = p.first.first;
            y = p.first.second;
            if (mp[x][y] == 'X') {
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
                if (y < 9) {
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
            if (x < 9) {
                if (y > 0) {
                    if (!v[x + 1][y - 1] && mp[x + 1][y - 1] != '#') {
                        v[x + 1][y - 1] = 1;
                        q.push(make_pair(make_pair(x + 1, y - 1), p.second + 1));
                    }
                }
                if (y < 9) {
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
            if (y < 9 && !v[x][y + 1] && mp[x][y + 1] != '#') {
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