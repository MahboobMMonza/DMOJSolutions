#include <bits/stdc++.h>

using namespace std;

char a[1000001], b[1000001];
int main() {
    scanf("%s%s", a, b);
    int arr[10][4] = {{1,1,1,1}, {2,4,8,6}, {3,9,7,1}, {4,6,4,6}, {5,5,5,5}, {6,6,6,6}, {7,9,3,1}, {8,4,2,6}, {9,1,9,1}, {0,0,0,0}}, sa = 0, sb = 0;
    for (int i = 0; i < strlen(a); i++) {
        (a[i] < 'a') ? sa += arr[(a[i] - 'A') % 10][i % 4] : sa += arr[(a[i] - 'a') % 10][i % 4];
        sa %= 10;
    }
    for (int i = 0; i < strlen(b); i++) {
        (b[i] < 'a') ? sb += arr[(b[i] - 'A') % 10][i % 4] : sb += arr[(b[i] - 'a') % 10][i % 4];
        sb %= 10;
    }
    if (sa == 0) sa = 10;
    if (sb == 0) sb = 10;
    printf("%d", sa + sb);
    return 0;
}