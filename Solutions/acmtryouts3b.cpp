#include <bits/stdc++.h>

using namespace std;

char l[1001];
int main() {
    int n;
    scanf("%d%*c", &n);
    while (n--) {
        scanf("%[^\n]%*c", l);
        printf("<3");
        for (int i = 0; i < strlen(l) - 1; i++) {
            if (l[i] == '<' && l[i + 1] == '3') printf(" <3");
        }
        printf("\n");
    }
    return 0;
}