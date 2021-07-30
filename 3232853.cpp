#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> f;

int ff(int s, int e) {
    unordered_set<int> v;
    int c = 0, n = f[s];
    bool fc = 0;
    while (!v.count(n)) {
        v.insert(n);
        if(f.count(n)) {
            if (n == e) {
                fc = 1;
            }
            if (!fc) c++;
            n = f[n];
        }
    }
    if (v.count(s) && v.count(e)) {
        return c;
    }
    return -1;
}

int main() {
    int n, a, b, x;
    scanf("%d", &n);
    while(n--) {
        scanf("%d%d", &a, &b);
        f[a] = b;
    }
    scanf("%d%d", &a, &b);
    while (a + b) {
        x = ff(a, b);
        (x == -1) ? printf("No\n") : printf("Yes %d\n", x);
        scanf("%d%d", &a, &b);
    }
    return 0;
}