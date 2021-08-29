#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define PRECISION cout.precision(3); cout.setf(ios::fixed);

#define infinite 9123456789
#define db cout << "Debug" << "\n";

#define ler_entrada freopen("test_input.txt", "r", stdin);

int n, m, aresta[20][20], memo[100010][20], ans = 1;

bool dp(int mask, int fim){
    // cout << mask << " " << fim << "\n";
    if(memo[mask][fim] != -1) return memo[mask][fim];
    if((mask & (1 << fim)) == 0) return memo[mask][fim] = false;

    vector<int> ativo;
    for(int i = 0; i < n; i++){
        int pot = (1 << i);
        if(pot & mask) ativo.pb(i);
    }

    for(auto u : ativo){
        if(u == fim) continue;
        if(!aresta[u][fim]) continue;
        if(dp(mask - (1 << fim), u)) return memo[mask][fim] = true;
    }
    return memo[mask][fim] = false;
}

void solve(){
    memset(memo, -1, sizeof(memo));

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        aresta[a][b]++;
        aresta[b][a]++;
    }

    for(int i = 0; i < n; i++) memo[(1 << i)][i] = 1;
    // cout << dp(15, 3) << "\n";
    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            if(dp(i, j)){
                ans = max(ans, (int) __builtin_popcount(i));
            }
        }
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
}