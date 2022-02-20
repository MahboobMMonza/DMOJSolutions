#include <bits/stdc++.h>

using namespace std;

char str[80];
int main() {
    int n, index;
    scanf("%d", &n);
    for (int t = 0; t < n; t++) {
        scanf("%d %[^\n]%*c", &index, str);
        printf("%d ", t + 1);
        for (int i = 0; i < 80; i++) {
            if (str[i] == '\0') {
                break;
            } else {
                if (i + 1 != index) {
                    printf("%c", str[i]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}