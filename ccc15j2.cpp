#include <bits/stdc++.h>

using namespace std;

char l[256];
int main() {
    int h = 0, s = 0;
    scanf("%[^\n]%*c", l);
    if (strlen(l) < 3) {
        printf("none");
        return 0;
    }
    for (int i = 0; i < strlen(l) - 3; i++) {
        if (l[i] == ':' && l[i + 1] == '-') {
            (l[i + 2] == ')') ? h++ : (l[i + 2] == '(') ? s++ : h += 0;
        }
    }
    (h == s) ? (h == 0) ? printf("none") : printf("unsure") : (h > s) ? printf("happy") : printf("sad");
    return 0;
}