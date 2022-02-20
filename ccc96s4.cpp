#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> conv;
void put(const string& s, int v) {
    conv[s] = v;
}

string sum(string s) {
    string ns[2];
    int t = 0, sum = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '+') {
            t++;
        } else if (s[i] != '=') {
            ns[t] += s[i];
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < ns[i].length(); j++) {
            if (ns[i][j] == 'I') {
                if (j == ns[i].length() - 1 || ns[i][j + 1] == 'I') {
                    sum += conv[ns[i].substr(j, 1)];
                } else {
                    sum += conv[ns[i].substr(j, 1) + ns[i][j + 1]];
                    j++;
                }
            } else if (ns[i][j] == 'X') {
                if (j == ns[i].length() - 1 || (ns[i][j + 1] != 'L' && ns[i][j + 1] != 'C')) {
                    sum += conv[ns[i].substr(j, 1)];
                } else {
                    sum += conv[ns[i].substr(j, 1) + ns[i][j + 1]];
                    j++;
                }
            } else if (ns[i][j] == 'C') {
                if (j == ns[i].length() - 1 || (ns[i][j + 1] != 'M' && ns[i][j + 1] != 'D')) {
                    sum += conv[ns[i].substr(j, 1)];
                } else {
                    sum += conv[ns[i].substr(j, 1) + ns[i][j + 1]];
                    j++;
                }
            }
            else {
                sum += conv[ns[i].substr(j, 1)];
            }
        }
    }
    if (sum > 1000) {
        return s + "CONCORDIA CUM VERITATE";
    }
    if (sum == 1000) {
        s+=("M");
        sum -= 1000;
    }
    if (sum >= 900) {
        s+=("CM");
        sum -= 900;
    }
    if (sum >= 800) {
        s+=("DCCC");
        sum -= 800;
    }
    if (sum >= 700) {
        s+=("DCC");
        sum -= 700;
    }
    if (sum >= 600) {
        s+=("DC");
        sum -= 600;
    }
    if (sum >= 500) {
        s+=("D");
        sum -= 500;
    }
    if (sum >= 400) {
        s+=("CD");
        sum -= 400;
    }
    if (sum >= 300) {
        s+=("CCC");
        sum -= 300;
    }
    if (sum >= 200) {
        s+=("CC");
        sum -= 200;
    }
    if (sum >= 100) {
        s+=("C");
        sum -= 100;
    }
    if (sum >= 90) {
        s+=("XC");
        sum -= 90;
    }
    if (sum >= 80) {
        s+=("LXXX");
        sum -= 80;
    }
    if (sum >= 70) {
        s+=("LXX");
        sum -= 700;
    }
    if (sum >= 60) {
        s+=("LX");
        sum -= 60;
    }
    if (sum >= 50) {
        s+=("L");
        sum -= 50;
    }
    if (sum >= 40) {
        s+=("XL");
        sum -= 40;
    }
    if (sum >= 30) {
        s+=("XXX");
        sum -= 30;
    }
    if (sum >= 20) {
        s+=("XX");
        sum -= 20;
    }
    if (sum >= 10) {
        s+=("X");
        sum -= 10;
    }
    if (sum >= 9) {
        s+=("IX");
        sum -= 9;
    }
    if (sum >= 8) {
        s+=("VIII");
        sum -= 8;
    }
    if (sum >= 7) {
        s+=("VII");
        sum -= 7;
    }
    if (sum >= 6) {
        s+=("VI");
        sum -= 6;
    }
    if (sum >= 5) {
        s+=("V");
        sum -= 5;
    }
    if (sum >= 4) {
        s+=("IV");
        sum -= 4;
    }
    if (sum >= 3) {
        s+=("III");
        sum -= 3;
    }
    if (sum >= 2) {
        s+=("II");
        sum -= 2;
    }
    if (sum >= 1) {
        s+=("I");
    }
    return s;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    put("I", 1);
    put("IV", 4);
    put("V", 5);
    put("IX", 9);
    put("X", 10);
    put("XL", 40);
    put("L", 50);
    put("XC", 90);
    put("C", 100);
    put("CD", 400);
    put("D", 500);
    put("CM", 900);
    put("M", 1000);
    int t;
    string res, q;
    cin >> t;
    while (t--) {
        cin >> q;
        cout << sum(q) << '\n';
    }
    return 0;
}