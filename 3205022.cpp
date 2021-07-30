#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, e;
    scanf("%d%d", &a, &e);
    if (a >= 3 && e <= 4) {
        printf("TroyMartian\n");
    }
    if (a <= 6 && e >= 2) {
        printf("VladSaturnian\n");
    }
    if (a <= 2 && e <= 3) {
        printf("GraemeMercurian");
    }
    return 0;
}