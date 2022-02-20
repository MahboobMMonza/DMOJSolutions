#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> mv;
unordered_set<string> view;

char names[100001][31], mo[31];
int main() {
    int n, y, r;
    long s = 0;
    scanf("%d%d", &n, &y);
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &r);
        mv[string(names[i])] = r;
    }
    while (y--) {
        scanf("%s", mo);
        if (!view.count(mo)) {
            s += mv[mo];
            view.insert(mo);
        }
    }
    printf("%lld\n", s);
}