#include <bits/stdc++.h>

using namespace std;

char s[1000001];
int main() {
    scanf("%s", s);
    int h = 0, v = 0;
    for (int i = 0; i < strlen(s); i++) {
        h += (s[i] == 'H');
    }
    v = strlen(s) - h;
    h %= 2;
    v %= 2;
    if (h && v) {
        printf("4 3\n2 1");
    } else if (v) {
        printf("2 1\n4 3");
    } else if (h) {
        printf("3 4\n1 2");
    } else {
        printf("1 2\n3 4");
    }
    return 0;
}