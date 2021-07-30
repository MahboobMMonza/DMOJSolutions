#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, s, h;
    scanf("%d%d%d", &t, &s, &h);
    while (t--) {
        printf("*");
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < s; k++) {
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
    for (int e = 0; e < s + s + 3; e++) {
        printf("*");
    }
    printf("\n");
    while (h--) {
        for (int j = 0; j < s + 1; j++) {
            printf(" ");
        }
        printf("*\n");
    }    
    return 0;
}