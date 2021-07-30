#include <bits/stdc++.h>

using namespace std;

int main() {
    int a;
    while (true) {
        scanf("%d", &a);
        if (!a) {
            break;
        }
        for (int i = (int) sqrt(a); i > 0; i--) {
            if (!(a % i)) {
                printf("Minimum perimeter is %d with dimensions %d x %d\n", 2 * (i + (a / i)), i, a / i);
                break;
            }
        }
    }
    return 0;
}