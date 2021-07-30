#include <bits/stdc++.h>

using namespace std;

bool g(int s, int a, int c, int t) {
    return (t + c) % (s + a) < s;
}

int arr[4][3];
int main() {
    int x, n;
    bool a;
    scanf("%d", &x);
    while (x--) {
        scanf("%d", &n);
        int m = 1;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
            m *= arr[i][0] + arr[i][1];
        }
        a = 1;
        for (int t = 0; t < m; t++) {
            a = 1;
            for (int i = 0; i < n; i++) {
                if (g(arr[i][0], arr[i][1], arr[i][2], t)) {
                    a = 0;
                    break;
                }
            }
            if (a) {
                printf("%d\n", t);
                break;
            }
        }
        if (!a) {
            printf("Foxen are too powerful\n");
        }
    }
    return 0;
}