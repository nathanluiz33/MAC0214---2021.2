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

int main(){
	fastio;
	priority_queue<ii> PQ;
	vector<string> V;
	string s;
	cin>>ws;
	while(cin>>s) {
		if(s[0] == 'V') {
			if(!PQ.empty()) {
				int id = -1 * PQ.top().ss;
				PQ.pop();
				cout << V[id];
			}
			cout << endl;
		} else {
			int p; cin>>p;
			PQ.push({p, -sz(V)});
			V.pb(s);
		}
		cin>>ws;
	}
	return 0;
}

