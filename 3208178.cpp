#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    for (int i = x; i <= y; i += 60) {
        printf("All positions change in year %d\n", i);
    }
    return 0;
}