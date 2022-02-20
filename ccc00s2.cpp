#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> b;
    int i, n, x, v, f, j, o;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &v);
        b.push_back(v);
    }
    scanf("%d", &i);
    while (i != 77) {
        if (i == 99) {
            scanf("%d%d", &v, &f);
            x = b[v - 1];
            b.erase(b.begin() + v - 1);
            o = (int) round(x * (f / 100.0));
            x -= o;
            b.insert(b.begin() + v - 1, x);
            b.insert(b.begin() + v - 1, o);
        } else {
            scanf("%d", &j);
            b[j] += b[j - 1];
            b.erase(b.begin() + j - 1);
        }
        scanf("%d", &i);
    }
    for (int k = 0; k < b.size(); k++) {
        printf("%d ", b[k]);
    }
    return 0;
}