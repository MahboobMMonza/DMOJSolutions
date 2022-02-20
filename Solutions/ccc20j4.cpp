#include <bits/stdc++.h>

using namespace std;
char t[1001], s[1001];
int main() {
    scanf("%s%s", t, s);
    int ls = strlen(s), lt = strlen(t);
    if (ls > lt) {
        printf("no");
        return 0;
    }
    char c;
    for (int i = 0; i < strlen(s); i++) {
        if (strstr(t, s) != NULL) {
            printf("yes");
            return 0;
        }
        c = s[0];
        for (int j = 0; j < ls - 1; j++) {
            s[j] = s[j + 1];
        }
        s[ls - 1] = c;
    }
    printf("no");
    return 0;
}