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

const ll N = 1e5 + 1000;

struct Trie {
	int t[N][10], exit[N], nxt = 1;
	ll acum[N];
	void add(string& s) {
		int v = 0;
		for(int c: s)
			v = t[v][c-'0'] ? t[v][c-'0'] : (t[v][c-'0'] = nxt++);
		exit[v]++;
	}
	ll dfs(int u = 0) {
		For(i,0,10) if(t[u][i]) 
			acum[u] += dfs(t[u][i]);
		return acum[u] + exit[u];
	}
	ll solve() {
		dfs();
		ll ans = 0;
		For(i,1,nxt) 
			if(exit[i]) ans += acum[i];
		return ans;
	}
} trie;


int main(){
	fastio;
	int n; cin>>n;
	string s;
	For(i,0,n) {
		cin>>s;
		trie.add(s);
	}
	cout << trie.solve() << endl;
	return 0;
}

