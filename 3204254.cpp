#include <bits/stdc++.h>

using namespace std;

int main() {
    printf("Ready\n");
    char str[2];
    while (true) {
        scanf("%c%c%*c", &str[0], &str[1]);
        if (str[0] == ' ' && str[1] == ' ') {
            break;
        }
        char temp;
        if (str[0] > str[1]) {
            temp = str[0];
            str[0] = str[1];
            str[1] = temp;
        }
        ((str[0] == 'p' && str[1] == 'q') || (str[0] == 'b' && str[1] == 'd')) ? printf("Mirrored pair\n") : printf("Ordinary pair\n");
    }
    return 0;
}