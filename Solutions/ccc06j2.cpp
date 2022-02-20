#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c = 0;
    scanf("%d%d", &a, &b);
    for (int i = 1; i <= a; i++) {
        if (10 - i > 0 && 10 - i <= b) {
            c++;
        }
    }
    (c == 1) ? printf("There is 1 way to get the sum 10.") : printf("There are %d ways to get the sum 10.", c);
    return 0;
}