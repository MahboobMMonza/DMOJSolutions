#include <bits/stdc++.h>

using namespace std;

char s[31];
int main() {
    scanf("%s", s);
    // I, O, S, H, Z, X, N
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] != 'I' && s[i] != 'O' && s[i] != 'S' && s[i] != 'H' && s[i] != 'Z' && s[i] != 'X' && s[i] != 'N') {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}