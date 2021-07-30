#include <bits/stdc++.h>

using namespace std;

int main() {
    int a = 0, b = 0, v, i;
    char x, y;
    scanf("%d ", &i);
    while(i != 7) {
        switch (i) {
            case 1:
                scanf("%c%d", &x, &v);
                (x == 'A') ? a = v : b = v;
                break;
            case 2:
                scanf("%c", &x);
                (x == 'A') ? printf("%d\n", a) : printf("%d\n", b);
                break;
            case 3:
                scanf("%c %c", &x, &y);
                (x == 'A') ?  a += ((y == 'A') ? a : b) : b += ((y == 'A') ? a : b);
                break;
            case 4:
                scanf("%c %c", &x, &y);
                (x == 'A') ?  a *= ((y == 'A') ? a : b) : b *= ((y == 'A') ? a : b);
                break;
            case 5:
                scanf("%c %c", &x, &y);
                (x == 'A') ?  a -= ((y == 'A') ? a : b) : b -= ((y == 'A') ? a : b);
                break;
            case 6:
                scanf("%c %c", &x, &y);
                (x == 'A') ?  a /= ((y == 'A') ? a : b) : b /= ((y == 'A') ? a : b);
                break;
        }
        scanf("%d ", &i);
    }
    return 0;
}