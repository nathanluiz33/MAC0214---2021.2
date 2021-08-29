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

int dx[] = {0, 0, 1, -1, 1, -1, 1, -1, 0};
int dy[] = {1, -1, 0, 0, 1, 1, -1, -1, 0};

int n, m, p, a[1010][1010], seen[1010][1010];

void solve(){
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> a[i][j];

    for(int i = 1; i <= p; i++){
        int x, y; cin >> x >> y;
        for(int j = 0; j < 9; j++){
            int xx = x + dx[j], yy = y + dy[j];
            if(xx < 1 or xx > n or yy < 1 or yy > m) continue;
            if(a[xx][yy] == 0) continue;

            seen[xx][yy]++;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) if(seen[i][j]) ans++;
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
}