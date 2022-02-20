#include <bits/stdc++.h>

using namespace std;

bool mp[26][26];
struct p {
    char s[3];
};
vector<p> r;

int main() {
    p x;
    int c = 0;
    scanf("%s", x.s);
    while (strcmp(x.s, "**")) {
        r.push_back(x);
        mp[x.s[0] - 'A'][x.s[1] - 'A'] = mp[x.s[1] - 'A'][x.s[0] - 'A'] = 1;
        scanf("%s", x.s);
    }
    for (int it = 0; it < r.size(); it++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (i == j) mp[i][j] = mp[j][i] = 1;
                else mp[i][j] = mp[j][i] = 0;
            }
        }
        for (int ut = 0; ut < r.size(); ut++) {
            if (ut != it) mp[r[ut].s[0] - 'A'][r[ut].s[1] - 'A'] = mp[r[ut].s[1] - 'A'][r[ut].s[0] - 'A'] = 1;
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (mp[j][i]) {
                    for (int k = 0; k < 26; k++) {
                        if (mp[i][k]) mp[j][k] = 1;
                    }
                }
            }
        }
        if (!mp[0][1] && !mp[1][0]) {
            c++;
            printf("%s\n", r[it].s);
        }
    }
    printf("There are %d disconnecting roads.\n", c);
    return 0;
}