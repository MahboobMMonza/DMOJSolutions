#include <bits/stdc++.h>

using namespace std;

int l[100001];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    sort(l, l + n);
    for (int i = 0; i < n; i++) {
        printf("%d\n", l[i]);
    }
    return 0;
}