#include <bits/stdc++.h>

using namespace std;

struct p{char na[21]; int s, o;};

bool cmp(p a, p b) {
    return (a.s == b.s) ? a.o < b.o : a.s <= b.s;
}

p name[500];
int main() {
    int n, q, l, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", name[i].na, &name[i].s);
        name[i].o = i;
    }
    sort(name, name + n, cmp);
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &l, &m);
        bool f = 0;
        for (int i = 0; i < n; i++) {
            if (name[i].s >= l && name[i].s - l <= m) {
                f = 1;
                printf("%s\n", name[i].na);
                break;
            }
        }
        if (!f) printf("No suitable teacher!\n");
    }
    return 0;
}