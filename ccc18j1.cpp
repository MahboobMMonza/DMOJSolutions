#include <bits/stdc++.h>

using namespace std;

int main() {
    int nums[4];
    for (int i = 0; i < 4; i++) {
        scanf("%d", &nums[i]);
    }
    (nums[0] > 7 && nums[1] == nums[2] && nums[3] > 7) ? printf("ignore") : printf("answer");
    return 0;
}