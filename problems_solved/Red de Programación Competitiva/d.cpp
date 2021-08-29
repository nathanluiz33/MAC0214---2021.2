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

int n, m, a[200010];

int menor[800010], maior[800010];

void montar(int no, int ini, int fim){
    if(ini == fim){
        menor[no] = maior[no] = a[ini];
        return;
    }
    int meio = (ini + fim) / 2;
    montar(2 * no, ini, meio);
    montar(2 * no + 1, meio + 1, fim);
    menor[no] = min(menor[2 * no], menor[2 * no + 1]);
    maior[no] = max(maior[2 * no], maior[2 * no + 1]);
}

void att(int no, int ini, int fim, int k, int valor){
    if(ini == fim){
        menor[no] = maior[no] = valor;
        return;
    }
    int meio = (ini + fim) / 2;
    if(k <= meio) att(2 * no, ini, meio, k, valor);
    else att(2 * no + 1, meio + 1, fim, k, valor);
    menor[no] = min(menor[2 * no], menor[2 * no + 1]);
    maior[no] = max(maior[2 * no], maior[2 * no + 1]);
}

pair<int, int> qq(int no, int ini, int fim, int l, int r){
    if(l <= ini and fim <= r) return mp(maior[no], menor[no]);
    if(fim < l or r < ini) return mp(-infinite, infinite);
    int meio = (ini + fim) / 2;
    auto esq = qq(2 * no, ini, meio, l, r), dir = qq(2 * no + 1, meio + 1, fim, l, r);
    return mp(max(esq.first, dir.first), min(esq.second, dir.second));
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    montar(1, 1, n);

    for(int i = 1; i <= m; i++){
        string op; cin >> op;
        if(op == "UPD"){
            int k, valor; cin >> k >> valor;
            att(1, 1, n, k, valor);
            continue;
        }
        int l, r; cin >> l >> r;
        auto ans = qq(1, 1, n, l, r);
        if(op == "MIN") cout << ans.second << "\n";
        else cout << ans.first << "\n";
    }
}

signed main(){
    IOS;
    solve();
}