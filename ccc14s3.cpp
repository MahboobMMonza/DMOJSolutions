#include <bits/stdc++.h>

using namespace std;

int g(int n) {
    stack<int> s, b;
    int x, c = 1;
    while (n--) {
        scanf("%d", &x);
        s.push(x);
    }
    while (!s.empty()) {
        if (s.top() == c) {
            s.pop();
            c++;
        } else {
            if (!b.empty()) {
                if (b.top() == c) {
                    b.pop();
                    c++;
                } else {
                    b.push(s.top());
                    s.pop();
                }
            } else {
                b.push(s.top());
                s.pop();
            }
        }
    }
    while (!b.empty()) {
        if (b.top() == c) {
            b.pop();
            c++;
        } else {
            return 0;
        }
    }
    return 1;
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf(g(n) ? "Y\n" : "N\n");
    }
    return 0;
}