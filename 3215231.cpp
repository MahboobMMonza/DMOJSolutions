#include <bits/stdc++.h>

using namespace std;

char s[10001];
int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        int sum = 0;
        while (strlen(s) > 1) {
            sum = 0;
            for (int i = 0; i < strlen(s); i++) {
                sum += s[i] - '0';
            }
            strcpy(s, to_string(sum).c_str());
        }
        printf("%s\n", s);
    }
    return 0;
}