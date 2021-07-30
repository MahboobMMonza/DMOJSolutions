#include <bits/stdc++.h>

using namespace std;

char a[11], b[11], c[6];
int main() {
    int x;
    scanf("%[^\n]%*c%[^\n]", a, b);
    scanf("%d%*c", &x);
    while (x--) {
        scanf("%[^\n]%*c", c);
        bool flag = 1;
        for (int i = 0; i < 6; i++) {
            if (c[i] < 'Z' && strchr(b, c[i]) == NULL && strchr(a, c[i]) == NULL) {
                flag = 0;
                break;
            }
            if (c[i] > 'Z' && (strchr(b, c[i]) == NULL || strchr(a, c[i]) == NULL)) {
                flag = 0;
                break;
            }
        }
        flag ? printf("Possible baby.\n") : printf("Not their baby!\n");
    }
    return 0;
}