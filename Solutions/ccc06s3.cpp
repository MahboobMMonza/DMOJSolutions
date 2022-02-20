#include <bits/stdc++.h>

using namespace std;

struct p{double x, y;};

p v[33], r, j;

bool range(double p, double a, double b) {
    return (p <= max(a, b) && p >= min(a, b));
}

bool intersect(p a, p b) {
    double mab, mrj, yab, yrj;
    p poi;
    if (r.x == j.x) {
        if (a.x == b.x) {
            return range(a.x, r.x, j.x) || range(b.x, r.x, j.x);
        } else {
            mab = (b.y - a.y) / (b.x - a.x);
            yab = b.y - (mab * b.x);
            return range((mab * r.x) + yab, r.y, j.y);
        }
    }
    if (a.x == b.x) {
        mrj = (j.y - r.y) / (j.x - r.x);
        yrj = r.y - (mrj * r.x);
        return range((mrj * a.x) + yrj, a.y, b.y);
    }
    mab = (b.y - a.y) / (b.x - a.x);
    yab = b.y - (mab * b.x);
    mrj = (j.y - r.y) / (j.x - r.x);
    yrj = r.y - (mrj * r.x);
    if (mab == mrj) {
        return yrj == yab && (range(a.x, r.x, j.x) || range(b.x, r.x, j.x));
    }
    poi.x = (yab - yrj) / (mrj - mab);
    poi.y = (mrj * poi.x) + yrj;
    return range(poi.x, a.x, b.x) && range(poi.y, a.y, b.y) && range(poi.x, r.x, j.x) && range(poi.y, r.y, j.y);
}

int main() {
    int n, c = 0, s;
    scanf("%lf%lf%lf%lf", &r.x, &r.y, &j.x, &j.y);
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &s);
        for (int i = 1; i <= s; i++) {
            scanf("%lf%lf", &v[i].x, &v[i].y);
        }
        v[0] = v[s];
        for (int i = 0; i < s; i++) {
            if (intersect(v[i], v[i + 1])) {
                c++;
                break;
            }
        }
    }
    printf("%d", c);
    return 0;
}