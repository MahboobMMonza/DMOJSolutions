#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, a = 0;
    char c;
    scanf("%d ", &x);
    for (int i = 0; i < x; i++) {
        scanf("%c", &c);
        a += (c == 'A');
    }
    (a > x - a) ? printf("A") : (x - a > a) ? printf("B") : printf("Tie");
    return 0;
}