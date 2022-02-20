#include <bits/stdc++.h>

using namespace std;

struct qr{int i, c, v;};
struct cmp{bool operator()(const qr& a, const qr& b) {return a.c > b.c;}};
priority_queue<qr, vector<qr>, cmp> pq;

int l[2000] = {0}, d[10001] = {0}, q[100001] = {0};
int main() {
    int n, v, lc = 0;
    qr qv;
    scanf("%d%d", &n, &v);
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    for (int i = 0; i < v; i++) {
        qv.i = i;
        scanf("%d%d", &qv.v, &qv.c);
        pq.push(qv);
    }
    while (!pq.empty()) {
        qv = pq.top(); pq.pop();
        if (qv.c > lc) {
            for (int i = lc; i < qv.c; i++) {
                d[l[i]] = 1;
                for (int j = 1; j < 10001; j++) {
                    if (d[j]) {
                        if (j + l[i] < 10001) d[j + l[i]] = (d[j + l[i]]) ? min(d[j + l[i]], d[j] + 1) : d[j] + 1;
                    }
                }
            }
            lc = qv.c;
        }
        q[qv.i] = d[qv.v];
    }
    for (int i = 0; i < v; i++) {
        printf("%d\n", (q[i]) ? q[i] : -1);
    }
    return 0;
}