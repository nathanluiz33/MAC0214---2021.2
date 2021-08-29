// GMD
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define INF 1000000007
#define MOD 1000000007

ll mult(ll i) {
    return ((i * (i + 1)) / 2) % MOD;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    cout << (mult(n) * mult(m)) % MOD << "\n";
}

int main() {
	FASTIO;
	int tst; cin >> tst; while (tst--)
	solve();
	return 0;
}
