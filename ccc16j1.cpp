#include <bits/stdc++.h>

using namespace std;

int main() {
    int w = 0;
    char c;
    for (int i = 0; i < 6; i++) {
        scanf("%c%*c", &c);
        w += (c == 'W');
    }
    (w > 4) ? printf("1") : (w > 2) ? printf("2") : (w > 0) ? printf("3") : printf("-1");
    return 0;
}