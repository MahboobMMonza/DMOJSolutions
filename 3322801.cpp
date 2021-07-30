#include <bits/stdc++.h>

using namespace std;

int main() {
    priority_queue<int> pq;
    int n, w, c = 0;
    bool t = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &w);
        pq.push(w);
    }
    while (!pq.empty()) {
        if (pq.top() <= 100) {
            c += pq.top();
            if (t) {
                break;
            }
            t = 1;
        }
        pq.pop();
    }
    printf("%d\n", c);
    return 0;
}