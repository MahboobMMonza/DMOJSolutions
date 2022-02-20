#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 2e5+5;
struct E { int u, v, w; } e[MM];
int n, m, p[MM], dis[MM]; vector<pi> adj[MM];
bool cmp(E x, E y) { return x.w > y.w; }
int fd(int d) { return p[d]==d? p[d]: p[d]= fd(p[d]); }
void dfs(int u, int pa){
    for(pi e: adj[u]){
        int v = e.first, w = e.second;
        if(v != pa) { dis[v] = min(dis[u], w);  dfs(v, u); }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e, e+m, cmp);
    for(int i=1; i<=n; i++) p[i] = i;
    int cnt = 0;
    for(int i=0; i<m; i++){
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if(fd(u) != fd(v)){
            p[fd(u)] = fd(v); cnt++;
            adj[u].push_back({v, w}); adj[v].push_back({u, w});
        }
        if(cnt == n-1) break;
    }
    dis[1] = 1e9; dfs(1, 0);  dis[1] = 0;
    for(int i=1; i<=n; i++) cout << dis[i] << "\n";
}