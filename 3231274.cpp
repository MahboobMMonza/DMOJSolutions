#include <bits/stdc++.h>

using namespace std;

char mp[101][101];
int main() {
    for (int i = 0; i < 100; i++) {
        mp[0][i] = 'G';
    }
    int t, hi, wi, n, h, w, tr;
    char m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &hi, &wi, &n);
        for (int i = 1; i <= hi; i++) {
            scanf("%s%*c", mp[i]);
        }
        h = 0;
        w = 0;
        tr = 0;
        while (n--) {
            scanf("%c%*c", &m);
            switch (m) {
                case 'R':
                    if (mp[h][w] == 'E' || (h < hi && mp[h + 1][w] == 'E')) {
                        if (mp[h][w] == 'E' && h < hi && mp[h + 1][w] == 'E') {
                            h++;
                        }
                        while (h < hi && mp[h + 1][w] == 'E') {
                            h++;
                        }
                    }
                    if (w < wi - 1 && mp[h][w + 1] != 'S') {
                        w++;
                        if (mp[h][w] == 'T') {
                            tr++;
                            mp[h][w] = 'E';
                        }
                    }
                    break;
                case 'L':
                    if (mp[h][w] == 'E' || (h < hi && mp[h + 1][w] == 'E')) {
                        if (mp[h][w] == 'E' && h < hi && mp[h + 1][w] == 'E') {
                            h++;
                        }
                        while (h < hi && mp[h + 1][w] == 'E') {
                            h++;
                        }
                    }
                    if (w > 0 && mp[h][w - 1] != 'S') {
                        w--;
                        if (mp[h][w] == 'T') {
                            tr++;
                            mp[h][w] = 'E';
                        }
                    }
                    break;
                case 'D':
                    if (mp[h][w] == 'E' || (h < hi && mp[h + 1][w] == 'E')) {
                        if (mp[h][w] == 'E' && h < hi && mp[h + 1][w] == 'E') {
                            h++;
                        }
                        while (h < hi && mp[h + 1][w] == 'E') {
                            h++;
                        }
                    }
                    if (h < hi && mp[h + 1][w] != 'S') {
                        h++;
                        if (mp[h][w] == 'T') {
                            tr++;
                            mp[h][w] = 'E';
                        }
                    }
                    break;
            }
        }
        printf("%d\n", tr);
    }
    return 0;
}