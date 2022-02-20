#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    set<pii> s;
    s.insert(make_pair(0, -1));
    s.insert(make_pair(0, -2));
    s.insert(make_pair(0, -3));
    s.insert(make_pair(1, -3));
    s.insert(make_pair(2, -3));
    s.insert(make_pair(3, -3));
    s.insert(make_pair(3, -4));
    s.insert(make_pair(3, -5));
    s.insert(make_pair(4, -5));
    s.insert(make_pair(5, -5));
    s.insert(make_pair(5, -4));
    s.insert(make_pair(5, -3));
    s.insert(make_pair(6, -3));
    s.insert(make_pair(7, -3));
    s.insert(make_pair(7, -4));
    s.insert(make_pair(7, -5));
    s.insert(make_pair(7, -6));
    s.insert(make_pair(7, -7));
    s.insert(make_pair(6, -7));
    s.insert(make_pair(5, -7));
    s.insert(make_pair(4, -7));
    s.insert(make_pair(3, -7));
    s.insert(make_pair(2, -7));
    s.insert(make_pair(1, -7));
    s.insert(make_pair(0, -7));
    s.insert(make_pair(-1, -7));
    s.insert(make_pair(-1, -6));
    s.insert(make_pair(-1, -5));
    int x = -1, y = -5, d;
    char c;
    scanf("%c %d", &c, &d);
    while (c != 'q') {
        switch (c) {
            case 'l':
                while (d--) {
                    x--;
                    if (!s.count(make_pair(x, y))) {
                        s.insert(make_pair(x, y));
                    } else {
                        printf("%d %d DANGER\n", x - d, y);
                        return 0;
                    }
                }
                printf("%d %d safe\n", x, y);
                break;
            case 'r':
                while (d--) {
                    x++;
                    if (!s.count(make_pair(x, y))) {
                        s.insert(make_pair(x, y));
                    } else {
                        printf("%d %d DANGER\n", x + d, y);
                        return 0;
                    }
                }
                printf("%d %d safe\n", x, y);
                break;
            case 'u':
                while (d--) {
                    y++;
                    if (!s.count(make_pair(x, y))) {
                        s.insert(make_pair(x, y));
                    } else {
                        printf("%d %d DANGER\n", x, y + d);
                        return 0;
                    }
                }
                printf("%d %d safe\n", x, y);
                break;
            case 'd':
                while (d--) {
                    y--;
                    if (!s.count(make_pair(x, y))) {
                        s.insert(make_pair(x, y));
                    } else {
                        printf("%d %d DANGER\n", x, y - d);
                        return 0;
                    }
                }
                printf("%d %d safe\n", x, y);
                break;
        }
        scanf("%c %d", &c, &d);
    }
    return 0;
}