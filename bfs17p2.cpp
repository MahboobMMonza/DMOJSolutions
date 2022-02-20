#include <bits/stdc++.h>

using namespace std;

char c[7];
int e[6] = {0};
int main() {
    int n, col = 0, m = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", c);
        if(!strcmp(c, "red")) {
            e[0]++;
        } else if(!strcmp(c, "orange")) {
            e[1]++;
        } else if(!strcmp(c, "yellow")) {
            e[2]++;
        } else if(!strcmp(c, "green")) {
            e[3]++;
        } else if(!strcmp(c, "blue")) {
            e[4]++;
        } else if(!strcmp(c, "black")) {
            e[5]++;
        }
    }
    for (int i = 0; i < 6; i++) {
        m = max(e[i], m);
    }
    col = n - m;
    printf("%d", min(m, col + 1) + col);
    return 0;
}