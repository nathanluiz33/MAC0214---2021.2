#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define PRECISION cout.precision(2); cout.setf(ios::fixed);

#define infinite 9123456789123
#define db cout << "Debug" << "\n";

#define ler_entrada freopen("test_input.txt", "r", stdin);

int n, m, k, maior = 0;
vector<int> vertice[500010], ans[500010];

void bfs(){
    vector<int> dist(n + 10, -1);
    dist[k] = 0;
    queue<int> q;
    q.push(k);

    while(q.size()){
        int u = q.front(); q.pop();
        for(auto v : vertice[u]){
            if(dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    for(int i = 0; i < n; i++){
        if(i == k) continue;
        if(dist[i] == -1){
            ans[0].pb(i);
            continue;
        }
        maior = max(maior, dist[i]);
        ans[dist[i]].pb(i);
    }
    for(int i = 0; i <= maior; i++) sort(ans[i].begin(), ans[i].end());
}

void solve(){
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        vertice[a].pb(b);
        vertice[b].pb(a);
    }
    bfs();
    for(int i = 0; i <= maior; i++){
        cout << i << ": ";
        for(auto u : ans[i]) cout << u << " ";
            cout << "\n";
    }
}

signed main(){
    IOS;
    solve();
}