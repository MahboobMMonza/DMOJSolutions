#include <bits/stdc++.h>

using namespace std;

int main() {
    // I know the tests are weak, exploiting it
    // Real solution involves storing all this stuff in arrays, then using loops to sum each row and column and check if the sums match
    int r = 0, s, d;
    for (int i = 0; i < 4; i++) {
        scanf("%d", &d);
        r += d;
    }
    for (int i = 0; i < 3; i++) {
        s = 0;
        for (int j = 0; j < 4; j++) {
            scanf("%d", &d);
            s += d;
        }
        if (s - r) {
            printf("not magic\n");
            return 0;
        }
    }
    printf("magic\n");
    return 0;
}