#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define fr front()
#define bk back()
#define sbf setbuf(stdout, 0)
#define ppf pop_front()
#define tp top()
#define ps push
#define pp pop()
#define fls fflush(stdout)
#define qu queue
#define st stack
#define pq priority_queue

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pl;
typedef pair<ull, ull> pull;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;
typedef pair<pi, pi> ppi;

char seq[500001];

int main() {
    scanf("%s", seq);
    int sl = strlen(seq), l = 0, m = 0, s = 0, fp = 0, bp = sl - 1, ans = 0;
    for (int i = 0; i < sl; i++) {
        if (seq[i] == 'L') l++;
        else if (seq[i] == 'S') s++;
    }
    m = sl - (l + s);
    fp = l;
    while (seq[fp] != 'L' && fp < sl) fp++;
    while (seq[bp] != 'L' && bp > l) bp--;
    for (int i = 0; i < l; i++) {
        if (seq[i] == 'M') {
            ans++;
            seq[i] = 'L';
            seq[fp] = 'M';
            while (seq[fp] != 'L' && fp < sl) fp++;
        } else if (seq[i] == 'S') {
            ans++;
            seq[i] = 'L';
            seq[bp] = 'S';
            while (seq[bp] != 'L' && bp > l) bp--;
        }
    }
    for (int i = l; i < l + m; i++) {
        if (seq[i] != 'M') ans++;
    }
    printf("%d\n", ans);
    return 0;
}