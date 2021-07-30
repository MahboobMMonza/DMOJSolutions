#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define fr front()
#define bk back()
#define ppf pop_front()
#define tp top()
#define ps push
#define pp pop()

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

int a[1001][1001] = {}, b[1001][1001] = {};

int main() {
    int a1, a2 = a1 = 0, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
            b[j][i] = a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        int oa, ob, ea, eb = oa = ob = ea = 0;
        for (int j = 0; j < n; ++j) {
            if (!(j % 2)) {
                ea += a[i][j]; 
                eb += b[i][j];
            } else {
                oa += a[i][j];
                ob += b[i][j];
            }
        }
        a1 += max(oa, ea);
        a2 += max(ob, eb);
    }
    printf("%d\n", max(a1, a2));
}