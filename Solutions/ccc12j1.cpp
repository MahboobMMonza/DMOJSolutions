#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, s;
    scanf("%d%d", &l, &s);
    (s - l <= 0) ? printf("Congratulations, you are within the speed limit!") : (s - l <= 20) ? printf("You are speeding and your fine is $100.") : (s - l <= 30) ? printf("You are speeding and your fine is $270.") : printf("You are speeding and your fine is $500.");
    return 0;
}