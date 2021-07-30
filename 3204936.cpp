#include <bits/stdc++.h>

using namespace std;

int main() {
    int n[3];
    for (int i = 0; i < 3; i++) {
        scanf("%d", &n[i]);
    }
    printf("The 1-3-sum is %d", 91 + n[0] + 3 * n[1] + n[2]);
    return 0;
}