#include <bits/stdc++.h>

using namespace std;

int main() {
    int b, n, y, p, c = 0;
    scanf("%d%d%d%d", &b, &n, &y, &p);
    for (int i = 0; i * y <= p; i++) {
        for (int j = 0; j * n <= p ; ++j) {
            for (int k = 0; k * b <= p; ++k) {
                if (i * y + j * n + k * b <= p && i + j + k > 0) {
                    c++;
                    printf("%d Brown Trout, %d Northern Pike, %d Yellow Pickerel\n", k, j, i);
                }
            }
        }
    }
    printf("Number of ways to catch fish: %d", c);
    return 0;
}