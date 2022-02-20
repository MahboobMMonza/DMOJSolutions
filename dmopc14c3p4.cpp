#include <bits/stdc++.h>

using namespace std;

int arr[100001] = {0};
vector<int> f[100001];

int main() {
    for (int i = 1; i < 100001; i++) {
        for (int j = i; j < 100001; j += i) {
            arr[j]++;
        }
        f[arr[i]].push_back(i);
    }
    int t, k, a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &k, &a, &b);
        printf("%d\n", upper_bound(f[k].begin(), f[k].end(), b) - lower_bound(f[k].begin(), f[k].end(), a));
    }
    return 0;
}