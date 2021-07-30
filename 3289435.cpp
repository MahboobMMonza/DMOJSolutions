#include <bits/stdc++.h>

using namespace std;

int main() {
    int abc[7] = {0}, a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < 7; i++) {
        scanf("%d", &abc[i]);
    }
    sort(abc, abc + 7);
    a = abc[0];
    d = abc[6] - a;
    for (int i = 1; i < 6; i++) {
        for (int j = 1; j < 6; j++) {
            if (d - abc[i] == abc[j]) {
                b = abc[j];
                break;
            }
        }
        if (!b) break;
    }
    c = abc[6] - b - a;
    printf("%d %d %d", a, b, c);
    return 0;
}