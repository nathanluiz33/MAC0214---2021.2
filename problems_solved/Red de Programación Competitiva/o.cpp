// GMD
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define INF 1000000007
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    priority_queue<pair<ll, string>> p;
    for (int i = 0; i < n; i++) {
        string s;
        ll c;
        cin >> s >> c;
        p.push({c, s});
    }
    vector<string> resn;
    ll resc = 1;
    while (!p.empty() && resn.size() < 3) {
        resc *= p.top().first;
        resn.push_back(p.top().second);
        p.pop();
    }
    sort(resn.begin(), resn.end());
    for (string s : resn) {
        cout << s << " ";
    }
    cout << resc << endl;
}

int main() {
	FASTIO;
	//int tst; cin >> tst; while (tst--)
	solve();
	return 0;
}
