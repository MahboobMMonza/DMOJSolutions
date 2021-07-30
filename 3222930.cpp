#include <bits/stdc++.h>

using namespace std;

int ds[1000] = {0};
int main() {
    double h, dam, cur = 0;
    int D, E, t, d[5][2] = {0}, l, x, maxTime = 0;
    scanf("%lf%d%d", &h, &D, &E);
    for(int i = 0; i < D; i++){
        scanf("%d%d", &d[i][0], &d[i][1]);
    }
    for (int i = 0; i < E; i++) {
        scanf("%d%d%d", &t, &l, &x);
        ds[t] += x;
        ds[t + l] -= x;
        maxTime = max(maxTime, t + l);
    }
    for (int i = 0; i < maxTime; i++) {
        cur += ds[i] + 0.0;
        dam = cur;
        for (int j = 0; j < D; j++) {
            dam = max(0.0, min((cur - d[j][1]) * (1.0 - (d[j][0] / 100.0)), dam));
        }
        h -= dam;
    }
    (h <= 0)? printf("DO A BARREL ROLL!") : printf("%.2lf", h);
    return 0;
}