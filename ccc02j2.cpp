#include <bits/stdc++.h>

using namespace std;

bool notVowel(char c) {
    return (c != 'a' && c != 'e' && c != 'o' && c != 'i' && c != 'u' && c != 'y');
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    while (s != "quit!") {
        if (s.length() > 3) {
            if ( s.substr(s.length() - 2) == "or") {
                (notVowel(s[s.length() - 3])) ? (cout << s.substr(0, s.length() - 2) << "our\n") : (cout << s << "\n");
            } else {
                cout << s << "\n";
            }
        } else {
            cout << s << "\n";
        }
        cin >> s;
    }
    return 0;
}