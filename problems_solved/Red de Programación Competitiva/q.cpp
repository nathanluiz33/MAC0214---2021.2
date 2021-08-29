// GMD
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define INF 1000000007
#define MOD 1000000007

ll calc(ll n) {
    return (n * (3*n - 1)) / 2;
}

void solve() {
    ll c;
    cin >> c;
    ll l = 1, r = 2000000;
    while (l < r) {
        ll m = (l + r + 1) / 2;
        if (calc(m) <= c) {
            l = m;
        } else {
            r = m-1;
        }
    }

    ll lw = calc(l);
    ll hw = calc(l+1);

    if (c - lw <= hw - c) cout << lw << "\n";
    else cout << hw << "\n";
}

int main() {
	FASTIO;
	int tst; cin >> tst; while (tst--)
	solve();
	return 0;
}
