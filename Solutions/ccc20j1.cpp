#include <bits/stdc++.h>

using namespace std;

int main() {
    int s, m, l;
    scanf("%d%d%d", &s, &m, &l);
    ((s + m + m + l + l + l) >= 10) ? printf("happy") : printf("sad");
    return 0;
}