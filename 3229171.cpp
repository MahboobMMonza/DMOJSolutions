#include <bits/stdc++.h>

using namespace std;
string arr[1000001];
bool cmp(string a, string b) {return a + b > b + a;};
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n, cmp);
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    return 0;
}