#include <bits/stdc++.h>

using namespace std;

int main() {
    int r[4] = {0};
    scanf("%d%d%d%d", &r[0], &r[1], &r[2], &r[3]);
    (r[0] < r[1] && r[1] < r[2] && r[2] < r[3]) ? printf("Fish Rising") : (r[0] > r[1] && r[1] > r[2] && r[2] > r[3]) ? printf("Fish Diving") : (r[0] == r[1] && r[0] == r[2] && r[0] == r[3]) ? printf("Fish At Constant Depth") : printf("No Fish");
    return 0;
}