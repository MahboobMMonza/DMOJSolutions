#include <bits/stdc++.h>

using namespace std;

char ins[10][11];
int main() {
    int l = 0;
    scanf("%[^\n]%*c", ins[l]);
    while (strcmp(ins[l], "SCHOOL")) {
        l++;
        scanf("%[^\n]%*c", ins[l]);
    }
    l--;
    for (int i = l; i >= 0; i--) {
        if (!(i % 2)) {
            (ins[i][0] == 'L') ? printf("Turn RIGHT ") : printf("Turn LEFT ");
        } else {
            printf("onto %s street.\n", ins[i]);
        }
    }
    printf("into your HOME.");
    return 0;
}