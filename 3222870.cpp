#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    printf("%d in Ottawa\n", t);
    (t >= 300) ? printf("%d in Victoria\n", (t - 300) % 2400) : printf("%d in Victoria\n", (2100 + t) % 2400);
    (t >= 200) ? printf("%d in Edmonton\n", (t - 200) % 2400) : printf("%d in Edmonton\n", (2200 + t) % 2400);
    (t >= 100) ?  printf("%d in Winnipeg\n", (t - 100) % 2400) : printf("%d in Winnipeg\n", (2300 + t) % 2400);
    printf("%d in Toronto\n", (t));
    printf("%d in Halifax\n", (t + 100) % 2400);
    (t % 100 < 30) ? printf("%d in St. John's\n", (t + 130) % 2400) : printf("%d in St. John's\n", (t + 200 - 30) % 2400);
    return 0;
}