#include <bits/stdc++.h>

using namespace std;

int ds[200002] = {0};
int main() {
    double h, dam, cd = 0;
    int D, E, t, d[5][2] = {0}, l, x, mt = 0;
    scanf("%lf%d%d", &h, &E, &D);
    for(int i = 0; i < D; i++) {
        scanf("%d%d", &d[i][0], &d[i][1]);
    }
    for (int i = 0; i < E; i++) {
        scanf("%d%d%d", &t, &l, &x);
        ds[t] += x;
        ds[t + l] -= x;
        mt = max(mt, t + l);
    }
    for (int i = 0; i < mt; i++) {
        cd += ds[i] + 0.0;
        dam = cd;
        for (int j = 0; j < D; j++) {
            dam = max(0.0, min((cd - d[j][0]) * (1.0 - (d[j][1] / 100.0)), dam));
        }
        h -= dam;
    }
    (h < 1) ? printf("Act Like A Cactus.") : printf("%.2lf", h);
    return 0;
}