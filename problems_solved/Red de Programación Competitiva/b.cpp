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

int n, q, a[1000010];

int sum[4000100];

void montar(int no, int ini, int fim){
    if(ini == fim){
        sum[no] = a[ini];
        return;
    }
    int meio = (ini + fim) / 2;
    montar(2 * no, ini, meio);
    montar(2 * no + 1, meio + 1, fim);
    sum[no] = sum[2 * no] + sum[2 * no + 1];
}

void att(int no, int ini, int fim, int k){
    if(ini == fim){
        sum[no] = a[k];
        return;
    }
    int meio = (ini + fim) / 2;
    if(k <= meio) att(2 * no, ini, meio, k);
    else att(2 * no + 1, meio + 1, fim, k);
    sum[no] = sum[2 * no] + sum[2 * no + 1];
}

int qq(int no, int ini, int fim, int l, int r){
    if(l <= ini and fim <= r) return sum[no];
    if(fim < l or r < ini) return 0;
    int meio = (ini + fim) / 2;
    return qq(2 * no, ini, meio, l, r) + qq(2 * no + 1, meio + 1, fim, l, r);
}

void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];

    montar(1, 1, n);
    for(int i = 1; i <= q; i++){
        char op; cin >> op;
        if(op == 'q'){
            int l, r; cin >> l >> r;
            cout << qq(1, 1, n, l, r) << "\n";
        }
        else{
            int k, x; cin >> k >> x;
            a[k] += x;
            att(1, 1, n, k);
        }
    }
}

signed main(){
    IOS;
    solve();
}