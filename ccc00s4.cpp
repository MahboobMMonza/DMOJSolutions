#include <bits/stdc++.h>

using namespace std;

int s[5281] = {0};
int c[32] = {0};
int main() {
    int l, n;
    scanf("%d%d", &l, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        s[c[i]] = 1;
    }
    for (int i = 1; i <= l; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i] != 0 && i + c[j] < 5281) {
                s[i + c[j]] = (s[i + c[j]] == 0) ? s[i] + 1 : min(s[i + c[j]], s[i] + 1);
            }
        }
    }
    (s[l] == 0) ? printf("Roberta acknowledges defeat.") : printf("Roberta wins in %d strokes.", s[l]);
    return 0;
}