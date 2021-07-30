#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define fr front()
#define bk back()
#define ppf pop_front()
#define tp top()
#define ps push
#define pp pop()

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

char ip[101];
set<string> ss;

int main() {
    int la, ls;
    string abc, s, cs;
    scanf("%s", ip);
    abc = ip;
    scanf("%s", ip);
    s = ip;
    la = abc.length();
    ls = s.length();
    for (int i = 0; i < la; i++) {
        for (int j = 0; j <= ls; j++) {
            //cs = s.substr(0, j) + abc[i] + s.substr(j);
            ss.insert(s.substr(0, j) + abc[i] + s.substr(j));
        }
    }
    for (int i = 0; i < ls; i++) {
        //cs = s.substr(0, i) + s.substr(i);
        ss.insert(s.substr(0, i) + s.substr(i + 1));
    }
    for (int i = 0; i < la; i++) {
        for (int j = 0; j < ls; j++) {
            cs = s;
            cs[j] = abc[i];
            ss.insert(cs);
        }
    }
    for (auto& x : ss) {
        if (x != s) printf("%s\n", x.c_str());
    }
}