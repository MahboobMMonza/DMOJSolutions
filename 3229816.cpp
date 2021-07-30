#include <bits/stdc++.h>

using namespace std;

int main() {
    int s, t[6];
    scanf("%d%d%*c%d%*c%d %d%*c%d%*c%d", &s, &t[0], &t[1], &t[2], &t[3], &t[4], &t[5]);
    while (s--) {
        t[3]--;
        if (t[3] < 0) {
            t[3] = 23;
            t[2]--;
        }
        if (t[2] < 1) {
            t[2] = 30;
            if (t[1] == 3) {
                t[2] = 28;
            } else if (t[1] == 1 || t[1] == 2 || t[1] == 4 || t[1] == 6 || t[1] == 8 || t[1] == 9 || t[1] == 11) {
                t[2] = 31;
            }
            t[1]--;
        }
        if (t[1] < 1) {
            t[1] = 12;
            t[0]--;
        }
    }
    printf("%4d/%02d/%02d %02d:%02d:%02d", t[0], t[1], t[2], t[3], t[4], t[5]);
    return 0;
}