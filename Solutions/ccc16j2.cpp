#include <bits/stdc++.h>

using namespace std;

int main() {
    int r = 0, s, d;
    int rw[4] = {0,0,0,0};
    for (int i = 0; i < 4; i++) {
        scanf("%d", &d);
        r += d;
        rw[i] += d;
    }
    for (int i = 0; i < 3; i++) {
        s = 0;
        for (int j = 0; j < 4; j++) {
            scanf("%d", &d);
            s += d;
            rw[j] += d;
        }
        if (s - r) {
            printf("not magic\n");
            return 0;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (s - rw[i]) {
            printf("not magic\n");
            return 0;
        }
    }
    printf("magic\n");
    return 0;
}
