#include <bits/stdc++.h>

using namespace std;

char gate[8];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", gate);
        if (gate[2] == '1' || gate[2] == '3' || gate[2] == '5' || gate[2] == '7' || gate[2] == '9' || gate[2] == 'B' || gate[2] == 'D' || gate[2] == 'F') {
            gate[2]--;
            printf("%s ", gate);
            gate[2]++;
            printf("%s", gate);
        } else {
            printf("%s", gate);
        }
        printf("\n");
    }
    return 0;
}