#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define fr front()
#define bk back()
#define ppf pop_front()
#define tp top()
#define ps push
#define pp pop()

typedef unsigned long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

// graph as char matrix
char mp[50][51];

// bfs search
int afk() {
    // variables, m[] stores possible move options
    int l, w, m[8] = {1, 0, -1, 0, 0, 1, 0, -1};
    // b for beginning coordinates
    pi b;
    // x is for the bfs, holds distance and coordinates
    pii x;
    // read input
    scanf("%d%d%*c", &l, &w);
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < l; j++) {
            scanf("%c", &mp[i][j]);
            if (mp[i][j] == 'C') {
                b = {i, j};
            }
        }
        scanf("%*c");
    }
    // bfs from coordinates of b, starting with distance of 0
    queue<pii> q;
    q.ps({0, b});
    // Mark current cell as visited
    mp[b.f][b.s] = 'X';
    while (!q.empty()) {
        // Get next coordinates and distance from queue
        x = q.fr; q.pp;
        // Check each possible move, and if the move is valid, then search available adjacent cells
        for (int i = 0; i < 8; i += 2) {
            int nr = x.s.f + m[i], nc = x.s.s + m[i + 1];
            if (nr > -1 && nr < w && nc > -1 && nc < l) {
                if (mp[nr][nc] != 'X') {
                    // if the current cell is W, then return distance of W
                    if (mp[nr][nc] == 'W') return x.f + 1;
                    // Current cell is unoccupied and valid, add to queue 
                    q.ps({x.f + 1, {nr, nc}});
                    mp[nr][nc] = 'X';
                }
            }
        }
    }
    return INT_MAX;
}

int main() {
    int t, d;
    scanf("%d", &t);
    // for t test cases
    for (int i = 0; i < t; i++) {
        // Get the distance of the current graph
        d = afk();
        // Print response given the information of distance, #notworth is d >= 60
        printf("%s\n", (d >= 60) ? "#notworth" : to_string(d).c_str());
    }
    return 0;
}