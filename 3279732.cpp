#include <bits/stdc++.h>

using namespace std;

int arr[1000001] = {0};
unordered_map<int, int> lpos;
int main() {
    int n, k, s = 0;
    scanf("%d%d", &n, &k);
    lpos[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        arr[i] = arr[i] % k;
        arr[i] += arr[i - 1];
        arr[i] %= k;
        if (!lpos.count(arr[i])) {
            lpos[arr[i]] = i;
        }
    }
    for (int j = n; j >= 1; j--) {
        s = max(s, j - lpos[arr[j]]);
    }
    printf("%d", s ? s : -1);
    return 0;
}