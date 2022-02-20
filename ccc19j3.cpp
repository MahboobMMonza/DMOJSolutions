#include <bits/stdc++.h>

using namespace std;

char s[81];
int main() {
    int n, c = 1;
    char x;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        c = 1;
        x = s[0];
        for (int i = 1; i < strlen(s); i++) {
            if (s[i] == x) c++;
            else {
                printf("%d %c ", c, x);
                x = s[i];
                c = 1;
            }
        }
        printf("%d %c\n", c, x);
    }
    return 0;
}