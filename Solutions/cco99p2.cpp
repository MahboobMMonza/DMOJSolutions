#include <bits/stdc++.h>

using namespace std;

#define z first
unordered_map<string, int> f;

bool cmp(string a, string b) {
    return f[a] > f[b];
}

string ord(int x) {
    if (x % 100 >= 11 && x % 100 <= 13) {
        return to_string(x) + "th";
    }
    if (x % 10 == 1) return to_string(x) + "st";
    if (x % 10 == 2) return to_string(x) + "nd";
    if (x % 10 == 3) return to_string(x) + "rd";
    return to_string(x) + "th";
}

vector<string> v;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    string x;
    int w, k, n, c, sc;
    f = {};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w >> k;
        v = {};
        f = {};
        while (w--) {
            cin >> x;
            f[x]++;
        }
        for (auto it = f.begin(); it != f.end(); it++) {
            v.push_back(it->z);
        }
        c = sc = 0;
        sort(v.begin(), v.end(), cmp);
        cout << ord(k) << " most common word(s):\n";
        for (int j = 0; j < v.size(); j++) {
            if (c == k - 1) {
                cout << v[j] << "\n";
            }
            if (j < v.size() - 1 && f[v[j]] != f[v[j + 1]]) {
                c += j + 1 - sc;
                sc = j + 1;
            }
        }
        cout << "\n";
    }
}