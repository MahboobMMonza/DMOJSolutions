#include <bits/stdc++.h>

using namespace std;

char dna[1000001];
int main() {
    int n;
    bool th = 0, ur = 0, o = 0;
    scanf("%d", &n);
    scanf("%s", dna);
    for (int i = 0; i < n; i++) {
        if (dna[i] == 'T') th = 1;
        if (dna[i] == 'U') ur = 1;
        if (dna[i] != 'A' && dna[i] != 'C' && dna[i] != 'G' && dna[i] != 'T' && dna[i] != 'U') o = 1;
    }
    if (!o) {
        if (!th && !ur) {
            printf("both\n");
        } else if (th && !ur) {
            printf("DNA\n");
        } else if (!th && ur) {
            printf("RNA\n");
        } else printf("neither\n");
    } else printf("neither\n");
    return 0;
}