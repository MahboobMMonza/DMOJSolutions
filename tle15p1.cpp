#include <bits/stdc++.h>

using namespace std;

class Ranking {
public: 
    char name[51];
    int mins;
    Ranking(){this->mins = 0;}
};

bool cmp(Ranking a, Ranking b) {
    return a.mins >= b.mins;
}

Ranking r[100];
int main() {
    int n, p;
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; i++) {
        scanf("%s", r[i].name);
    }
    while (p--) {
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            r[i].mins += x;
        }
    }
    sort(r, r + n, cmp);
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 3, r[i].name);
    }
    return 0;
}