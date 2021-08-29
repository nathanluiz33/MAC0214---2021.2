// GMD
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define INF 1000000007
#define MOD 1000000007

typedef vector<int> Vertex;

map<Vertex, vector<pair<Vertex, ll>>> adjs;
vector<int> val(7);

int n = 5040;

ll dij(Vertex r, Vertex g) {
    set<pair<ll, Vertex>> s;
    map<Vertex, ll> dist;
    s.insert({0, r});
    while (!s.empty()) {
        Vertex vi = (*s.begin()).second;
        ll vw = (*s.begin()).first;
        s.erase(s.begin());
        if (dist.find(vi) != dist.end()) continue;
        if (vi == g) return vw;
        dist[vi] = vw;
        for (auto p : adjs[vi]) {
            Vertex ai = p.first;
            ll aw = p.second;
            if (dist.find(ai) != dist.end()) continue;
            s.insert({vw + aw, ai});
        }
    }
    return -1;
}

vector<pair<int, int>> swaps = {
    {0, 1},
    {0, 3},
    {1, 4},
    {2, 3},
    {2, 5},
    {3, 4},
    {3, 6},
    {5, 6},
};

void print(vector<int> &p) {
    for (int a : p) cout << a << " ";
    cout << endl;
}

void solve() {
    map<int, queue<int>> mm;
    for (int i = 0; i < 7; i++) {
        cin >> val[i];
        mm[val[i]].push(i);
    }
    Vertex p(7);
    iota(p.begin(), p.end(), 0);
    Vertex s(p), e(p);
    for (int i = 0; i < 7; i++) {
        int x;
        cin >> x;
        e[i] = mm[x].front();
        mm[x].pop();
    }
    do {
        vector<int> a(p);
        for (auto sw : swaps) {
            int i = sw.first;
            int j = sw.second;
            swap(a[i], a[j]);
            ll cost = val[a[i]] + val[a[j]];
            adjs[p].push_back({a, cost});
            adjs[a].push_back({p, cost});
            swap(a[i], a[j]);
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << dij(s, e) << "\n";
}

int main() {
	FASTIO;
	//int tst; cin >> tst; while (tst--)
	solve();
	return 0;
}
