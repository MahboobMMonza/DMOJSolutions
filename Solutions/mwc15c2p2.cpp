#include <bits/stdc++.h>

using namespace std;


typedef pair<int, int> pii;

stack<pii> s;

int main() {
    int n, h;
    s.push({INT_MAX, 0});
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h);
        while (!s.empty() && h >= s.top().first) {
            s.pop();
        }
        printf("%d ", i - s.top().second);
        s.push({h, i});
    }
    return 0;
}