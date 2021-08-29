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

int n, m;
char a[1010][1010];

void solve(){
    cin >> n >> m;
    for(int i = 0; i <= n + 1; i++){
        for(int j = 0; j <= m + 1; j++){
            if(i < 1 or i > n or j < 1 or j > m){
                a[i][j] = '.';
                continue;
            }
            cin >> a[i][j];
        }
    }

    // for(int i = 0; i <= n + 1; i++){
    //     for(int j = 0; j <= m + 1; j++) cout << a[i][j];
    //         cout << "\n";
    // }

    int ans = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == a[i + 1][j]) continue;
            if(a[i][j] == a[i][j - 1] and a[i + 1][j] == a[i + 1][j - 1]) continue;
            ans++;
        }
    }

    for(int j = 0; j <= m; j++){
        for(int i = 1; i <= n; i++){
            if(a[i][j] == a[i][j + 1]) continue;
            if(a[i][j] == a[i - 1][j] and a[i][j + 1] == a[i - 1][j + 1]) continue;
            ans++;
        }
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
}