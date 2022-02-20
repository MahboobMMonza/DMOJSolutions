#include <bits/stdc++.h>

using namespace std;

int v[100001] = {0};
vector<int> c;
int main() {
    int x, n, a;
    scanf("%d%d", &x, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        v[a] = 1;
        c.push_back(a);
    }
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i]) {
                if (v[i + c[j]] <= x) {
                    v[i + c[j]] = (v[i + c[j]]) ? min(v[i + c[j]], v[i] + 1) : v[i] + 1;
                }
            }
        }
    }
    printf("%d", v[x]);
    return 0;
}