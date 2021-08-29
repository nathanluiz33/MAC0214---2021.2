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

const int mod = 1e9 + 7;
const int N = 1e5 + 9;

int fat[N], inv[N];

int fast_exp(int b, int e) {
   if(e == 0) return 1;
   
   int ans = fast_exp(b, e / 2);
   ans = (ans * ans) % mod;
   if(e % 2 == 1) ans = (ans * b) % mod;
   
   return ans;
}

void init() {
   fat[0] = fat[1] = 1;
   inv[0] = inv[1] = 1;
   for(int i = 2; i < N; i++) {
      fat[i] = (i * fat[i-1])%mod;
      inv[i] = fast_exp(fat[i], mod - 2);
   }
}

int comb(int a, int b) {
   return fat[a] * inv[b] % mod * inv[a-b] % mod;
}

int x, y, pref[2010], primo[2010];

void crivo(){
    vector<int> jafoi(2010);
    for(int i = 2; i < 2010; i++){
        if(jafoi[i]) continue;
        primo[i]++;
        for(int j = i; j < 2010; j += i) jafoi[j]++;
    }
}

void precalc(){
    init();
    crivo();
    for(int n = 1; n <= 2000; n++){
        pref[n] = pref[n - 1];
        for(int i = 1; i < n; i++){
            int j = n - i;
            if(!primo[j] or !primo[i]) continue;

            pref[n] = (pref[n] + comb(n, i)) % mod;
        }
    }
}

void solve(){
    cin >> x >> y;
    cout << (pref[y] - pref[x - 1] + mod) % mod << "\n";
}

signed main(){
    precalc();
    IOS; int t; cin >> t;
    for(int i = 1; i <= t; i++)
        solve();
}