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

int n, m, pai[10010], tam[10010];

int find_pai(int x){
    if(pai[x] == x) return x;
    return pai[x] = find_pai(pai[x]);
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) pai[i] = i, tam[i] = 1;

    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        int A = find_pai(a), B = find_pai(b);
        pai[B] = A;
        tam[A] += tam[B];
    }

    int esq = 0, dir = 0;
    for(int i = 1; i <= n; i++){
        if(pai[i] != i) continue;
        if(tam[i] == 1) dir++;
        else esq++;
    }
    cout << esq << " " << dir << "\n";
}

signed main(){
    IOS;
    solve();
}