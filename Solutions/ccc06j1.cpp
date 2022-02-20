#include <bits/stdc++.h>

using namespace std;

int main() {
    int menu[4][4] = {{461, 431, 420, 0}, {100, 57, 70, 0}, {130, 160, 118, 0}, {167, 266, 75, 0}}, c = 0, x;
    for (int i = 0; i < 4; i++) {
        scanf("%d", &x);
        c += menu[i][x - 1];
    }
    printf("Your total Calorie count is %d.", c);
    return 0;
}