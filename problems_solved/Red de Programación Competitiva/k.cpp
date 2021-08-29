#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) ll((x).size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cerr << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
#define roF(i,a,b) for(ll i = ll(a); i >= ll(b); i--)
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const ll N=1e6;
const ll  INF = 1e18;

vector<array<ll, 3> > E;

int p[N];

int find(int x) {
	return x == p[x] ? p[x] : (p[x] = find(p[x]));
}

void uni(int u, int v) {
	p[find(u)] = find(v);
}

int main(){
	fastio;
	int n, m; cin>>n>>m;
	For(i,0,n) p[i] = i;
	For(i,0,m) {
		ll u, v, w; cin>>u>>v>>w;
		u--, v--;
		E.pb({w, u, v});
	}
	sort(all(E));
	ll ans = 0;
	for(auto e: E) {
		if(find(e[1]) == find(e[2])) continue;
		uni(e[1], e[2]);
		ans += e[0];
	}
	cout << ans << endl;
	return 0;
}

