// GMD
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define INF 1000000007
#define MOD 1000000007

void print(vector<int> &p) {
    for (int i = 0; i < 6; i++) {
        if (i > 0) cout << " ";
        cout << char('A' + i) << ":" << p[i];
    }
}

void solve() {
    int p;
    cin >> p;

    vector<int> t(6, 0);

    for (int i = 0; i < p; i++) {
        vector<int> p(6, 0);
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            char g;
            cin >> g;
            int gv = g - 'A';
            p[gv]++;
            t[gv]++;
        }
        print(p);
        cout << "\n";
    }

    cout << "TOTAL: ";
    print(t);
    cout << "\n";

}

int main() {
	FASTIO;
	//int tst; cin >> tst; while (tst--)
	solve();
	return 0;
}
