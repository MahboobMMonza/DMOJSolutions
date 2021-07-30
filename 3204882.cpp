#include <bits/stdc++.h>

using namespace std;

int main() {
    double w, h, bmi;
    scanf("%lf%lf", &w, &h);
    bmi = w / (h * h);
    (bmi > 25.0) ? printf("Overweight") : (bmi < 18.5) ? printf("Underweight") : printf("Normal weight");
    return 0;
}