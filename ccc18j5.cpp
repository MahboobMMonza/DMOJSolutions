#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > v(10004);
bool visited[10004];

int dist = INT_MAX, cnt = 0;
void read_pages(int page){
    queue<pair<int,int> >q;
    q.push(make_pair(1, page));
    visited[page] = true;
    cnt++;
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        if(v[curr.second].empty()){
            dist = min(curr.first, dist);
        }
        for(int i = 0; i < v[curr.second].size(); i++){
            int child = v[curr.second][i];
            if(visited[child] == false){
                q.push(make_pair(curr.first + 1, child));
                visited[child] = true;
                cnt++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);;
    int n; cin >> n;
    int x;
    for(int i = 1; i <= n; i++){
        int l; cin >> l;
        for(int j = 1; j <= l; j++){
            cin >> x;
            v[i].push_back(x);
        }
    }
    read_pages(1);
    if(cnt == n){
        cout << "Y\n";
    }else{
        cout << "N\n";
    }
    cout << dist;
    return 0;
}