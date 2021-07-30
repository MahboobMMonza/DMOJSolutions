#include <bits/stdc++.h>

using namespace std;

char icon[3][4] = {"*x*", " xx", "* *"};
int main() {
    int x;
    scanf("%d", &x);
    for (int i = 0; i < 3; i++) {
        for (int h = 0; h < x; h++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < x; k++) {
                    printf("%c", icon[i][j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}