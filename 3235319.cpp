#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int fr[50][50] = {0};

int su() {
    fr[1][6] = fr[2][6] = fr[3][6] = fr[4][6] = fr[5][6] = fr[7][6] = fr[6][1] = fr[6][2] = fr[6][3] = fr[6][4] = fr[6][5] = fr[6][7] = fr[3][4] = 1;
    fr[3][15] = fr[15][3] = fr[3][5] = fr[4][5] = fr[5][3] = fr[4][3] = fr[5][4] = fr[7][8] = fr[8][7] = fr[8][9] = fr[9][8] = fr[9][10] = fr[10][9] = 1;
    fr[9][12] = fr[12][9] = fr[10][11] = fr[11][10] = fr[12][11] = fr[11][12] = fr[12][13] = fr[13][12] = fr[13][15] = fr[15][13] = 1;
    fr[14][13] = fr[13][14] = fr[16][17] = fr[17][16] = fr[16][18] = fr[18][16] = fr[17][18] = fr[18][17] = 1;
    return 0;
}


int main() {
    su();
    char c;
    int x, y;
    bool f = 0;
    unordered_set<int> s;
    queue<pii> q;
    while (true) {
        scanf("%c%*c", &c);
        if (c == 'q') break;
        switch (c) {
            case 'i':
                scanf("%d%d\n", &x, &y);
                fr[x][y] = fr[y][x] = 1;
                break;
            case 'f':
                scanf("%d\n", &x);
                s.clear();
                for (int i = 1; i < 50; i++) {
                    if (fr[x][i] == 1) {
                        for (int j = 1; j < 50; j++) {
                            if (fr[i][j] == 1 && !fr[x][j] && j != x) {
                                s.insert(j);
                            }
                        }
                    }
                }
                printf("%d\n", s.size());
                break;
            case 'n':
                scanf("%d\n", &x);
                y = 0;
                for (int i = 1; i < 50; i++) {
                    y += (fr[x][i] == 1);
                }
                printf("%d\n", y);
                break;
            case 'd':
                scanf("%d%d\n", &x, &y);
                fr[x][y] = fr[y][x] = 0;
                break;
            case 's':
                scanf("%d%d\n", &x, &y);
                f = 0;
                for (int i = 1; i < 50; i++) {
                    if (fr[x][i] && i != x) {
                        q.push(make_pair(i, 1));
                        s.insert(i);
                    }
                }
                s.clear();
                while (!q.empty()) {
                    pii a = q.front(); q.pop();
                    if (a.first == y) {
                        f = 1;
                        printf("%d\n", a.second);
                        break;
                    }
                    for (int i = 1; i < 50; i++) {
                        if (fr[a.first][i] && i != x && !s.count(i)) {
                            q.push(make_pair(i, a.second + 1));
                            s.insert(i);
                        }
                    }
                }
                while (!q.empty()) q.pop();
                if (!f) printf("Not connected\n");
                break;
        }
    }
    return 0;
}