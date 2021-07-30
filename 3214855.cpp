#include <bits/stdc++.h>

using namespace std;

int arr[2][100] = {0};
int main() {
    int n, s = 0;
    char c;
    scanf("%d%*c", &n);
    for (int j = 0; j < n; j++) {
        scanf("%c", &c);
        arr[0][j] += (c == 'C');
    }
    scanf("%*c");
    for (int j = 0; j < n; j++) {
        scanf("%c", &c);
        arr[1][j] += (c == 'C');
        s += (arr[0][j] + arr[1][j] == 2);
    }
    printf("%d", s);
    return 0;
}