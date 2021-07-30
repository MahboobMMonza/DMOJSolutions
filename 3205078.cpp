#include <bits/stdc++.h>

using namespace std;

int main() {
    int s[3], sum = 0;
    for (int i = 0; i < 3; i++) {
        scanf("%d", &s[i]);
        sum += s[i];
    }
    (sum != 180) ? printf("Error") : (s[0] == s[1] || s[1] == s[2] || s[0] == s[2]) ? (s[0] == s[1] && s[1] == s[2]) ? printf("Equilateral") : printf("Isosceles") : printf("Scalene");
    return 0;
}