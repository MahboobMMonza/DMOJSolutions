#include <bits/stdc++.h>

using namespace std;
class Reading{
public:
    int val;
    int freq;
    Reading(){}
    Reading(int n) {
        val = n;
        freq = 0;
    }
};

bool cmp(Reading a, Reading b) {
    return (a.freq == b.freq) ? a.val >= b.val : a.freq >= b.freq;
}

Reading r[1001];
int main() {
    for (int i = 1; i < 1001; i++) {
        r[i] = Reading(i);
    }
    int n, x, d = 0, u = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        r[x].freq++;
        u += (r[x].freq == 1);
    }
    sort(r, r + 1001, cmp);
    if (r[0].freq != r[1].freq) {
        int j = 1;
        d = max(d, abs(r[j].val - r[0].val));
        j++;
        while (r[j].freq == r[j - 1].freq) {
            d = max(d, abs(r[j].val - r[0].val));
            j++;
        }
    } else {
        int j = 1;
        while (r[j].freq == r[j - 1].freq) {
            j++;
        }
        d = abs(r[j - 1].val - r[0].val);
    }
    printf("%d", d);
    return 0;
}