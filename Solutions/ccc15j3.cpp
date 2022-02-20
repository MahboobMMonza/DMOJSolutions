#include <bits/stdc++.h>

using namespace std;

char w[31];
int consonant(char x) {
    char v = 'u', c = (x == 'z') ? 'z' : (x + 1  == 'a' || x + 1 == 'e' || x + 1 == 'i' || x + 1 == 'o' || x + 1 == 'u') ? x + 2 : x + 1, vow[] = "aeio";
    for (int i = 0; i < 5; i++) {
        if (abs(x - vow[i]) < abs(x - v)) v = vow[i];
    }
    printf("%c%c", v, c);
    return 0;
}

int main() {
    scanf("%s", w);
    for (int i = 0; i < strlen(w); i++) {
        printf("%c", w[i]);
        (w[i] == 'a' || w[i] == 'e' || w[i] == 'i' || w[i] == 'o' || w[i] == 'u') ? 0 : consonant(w[i]);
    }
    return 0;
}