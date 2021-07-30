#include <bits/stdc++.h>

using namespace std;

struct rq{char c; int i, f;};

bool cmp(rq a, rq b) {
    return a.i < b.i;
}
char w[100001] = {0};
rq r[100001];
int f[26] = {0}, b[26] = {0};
int main() {
    int n, m, ms;
    char c;
    scanf("%d%d%*c", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%c %d %d%*c", &r[i].c, &r[i].f, &r[i].i);
    }
    sort(r, r + m, cmp);
    for (int q = 0; q < m; q++) {
        if (f[r[q].c - 'a'] > r[q].f) {
            printf("-1");
            return 0;
        }
        if (f[r[q].c - 'a'] < r[q].f) {
            for (int i = b[r[q].c - 'a']; i < r[q].i && f[r[q].c - 'a'] < r[q].f; i++) {
                if (w[i] == 0) {
                    w[i] = r[q].c;
                    f[r[q].c - 'a']++;
                }
            }
        }
        if (f[r[q].c - 'a'] < r[q].f) {
            printf("-1");
            return 0;
        }
        b[r[q].c - 'a'] = r[q].i;
    }
    ms = n;
    c = '$';
    for (int i = 0; i < 26; i++) {
        if (b[i] < ms) {
            ms = b[i];
            c = (char) ('a' + i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (w[i] == 0) {
            if (i >= ms) {
                w[i] = c;
            } else {
                printf("-1");
                return 0;
            }
        }
    }
    printf("%s", w);
    return 0;
}