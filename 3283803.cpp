#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, x, y;
    pii mx = {0,0}, mn = {100, 100};
    scanf("%d", &n);
    while (n--) {
        scanf("%d%*c%d", &x, &y);
        mx = {min(100, max(mx.f, x + 1)), min(100, max(mx.s, y + 1))};
        mn = {max(0, min(mn.f, x - 1)), max(0, min(mn.s, y - 1))};
    }
    printf("%d,%d\n%d,%d\n", mn.f, mn.s,mx.f, mx.s);
    return 0;
}