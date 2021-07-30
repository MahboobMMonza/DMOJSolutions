#include <bits/stdc++.h>

using namespace std;

char subject[20][26], verb[20][26], object[20][26];
int main() {
    int n, s, v, o;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d%d%*c", &s, &v, &o);
        for (int i = 0; i < s; i++) {
            scanf("%[^\n]%*c", subject[i]);
        }
        for (int i = 0; i < v; i++) {
            scanf("%[^\n]%*c", verb[i]);
        }
        for (int i = 0; i < o; i++) {
            scanf("%[^\n]%*c", object[i]);
        }
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < v; j++) {
                for (int k = 0; k < o; k++) {
                    printf("%s %s %s.\n", subject[i], verb[j], object[k]);
                }
            }
        }
    }
    return 0;
}