#include <bits/stdc++.h>

using namespace std;

struct cow {
    int x = 0, y = 0, fs = 2000000001, id = 0;
    cow(int id, int x, int y) {this->id = id, this->x = x, this->y = y;};
};

bool ncomp(cow a, cow b) {
    return a.x < b.x;
}

bool ecomp(cow a, cow b) {
    return a.y < b.y;
}

vector<cow> e, o;
int d[51] = {0};
int main() {
    int n, x, y;
    char c;
    scanf("%d%*c", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%c%*c%d%*c%d%*c", &c, &x, &y);
        if (c == 'E') {
            e.emplace_back(cow(i, x, y));
        } else o.emplace_back(cow(i, x, y));
    }
    sort(e.begin(), e.end(), ecomp);
    sort(o.begin(), o.end(), ncomp);
    for (auto & co : e) {
        for (auto & cc : o) {
            if (co.x < cc.x && co.y > cc.y && co.y < cc.fs && cc.x < co.fs) {
                int dx = cc.x - co.x, dy = co.y - cc.y;
                if (dx > dy && cc.x < co.fs) {
                    co.fs = cc.x;
                    d[co.id] = dx;
                    break;
                } else if (dy > dx && co.y < cc.fs) {
                    cc.fs = co.y;
                    d[cc.id] = dy;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        setbuf(stdout, 0);
        if (d[i] != 0) {
            printf("%d\n", d[i]);
        } else {
            printf("Infinity\n");
        }
    }
    return 0;
}