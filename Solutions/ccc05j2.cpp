#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c = 0;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++) {
        int f = 2;
        for (int j = 2; j * j <= i; j++) {
            (!(i % j)) ? ((j * j == i) ? f++ : f += 2) : f += 0;
        }
        (f == 4) ? c++ : c += 0;
    }
    printf("The number of RSA numbers between %d and %d is %d", a, b, c);
    return 0;
}