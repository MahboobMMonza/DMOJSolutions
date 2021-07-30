#include <bits/stdc++.h>

using namespace std;

int l[100], d[100];
int main() {
    int n; 
    for (int x = 0; x < 5; x++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &l[i]);
        }
        vector<int> v;
        bool f = 1;
        for (int i = n - 1; i > -1; i--) {
            if (l[i] > v.size()) {
                f = 0;
                printf("IMPOSSIBLE");
                break;
            }
            v.insert(v.end() - l[i], i);
        }
        if (f) {
            for (int i = 0; i < n; i++) {
                d[v[i]] = i;
            }
            for (int i = 0; i < n; i++) {
                printf("%d ", d[i] + 1);
            }
        }
        printf("\n");
    }
    return 0;
}