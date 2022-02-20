#include <bits/stdc++.h>

using namespace std;

int l[100][3];
int main() {
    int n, dis, t = 0, cl = 0, d = 0;
    scanf("%d%d", &n, &dis);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &l[i][0], &l[i][1], &l[i][2]);
    }
    while (d != dis) {
        t++;
        if (d < l[cl][0] || d > l[n - 1][0]) {
            d++;
        } else if (d == l[cl][0]) {
            if ((t) % (l[cl][1] + l[cl][2]) >= l[cl][1]) {
                d++;
                cl += (cl < n - 1);
            }
        }
    }
    printf("%d", t + 1);
    return 0;
}