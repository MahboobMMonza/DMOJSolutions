#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    for (int x = 0; x < 5; x++) {
        int in = 0;
        string s;
        getline(cin, s);
        for (int i = 1; i < s.length(); i++) {
            if (s.find(s.substr(i)) == 0) {
                in = i;
                break;
            }
        }
        (in == 0) ? cout << s << s << "\n" : cout << s << s.substr(s.length() - in) << "\n";
    }
    return 0;
}