#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))
// int pair 간단히
#define pii pair<int, int>
#define mp(X, Y) make_pair(X, Y)

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};


vector<bool> iswolf;
vector<ll> howmuch;
vector< vector<int> > leafs;

ll dfs(int curidx) {
	ll ret = 0;

	if(curidx == 1) {
		for(int i = 0; i < leafs[curidx].size(); i++) {
			int nextidx = leafs[curidx][i];
			ret += dfs(nextidx);
		}
	} else if(iswolf[curidx]) {
		for(int i = 0; i < leafs[curidx].size(); i++) {
			int nextidx = leafs[curidx][i];
			ll temp = dfs(nextidx);
			if(iswolf[curidx]) {
				if(temp < howmuch[curidx]) {
					howmuch[curidx] -= temp;
				} else {
					howmuch[curidx] = temp - howmuch[curidx];
					iswolf[curidx] = false;
				}
			} else {
				howmuch[curidx] += temp;
			}
		}
		
		if(iswolf[curidx]) {
			ret = 0;
		} else {
			ret = howmuch[curidx];
		}
	} else {
		ret += howmuch[curidx];
		for(int i = 0; i < leafs[curidx].size(); i++) {
			int nextidx = leafs[curidx][i];
			ret += dfs(nextidx);
		}
	}

	return ret;
}

int main(void) {
	// cin.tie(NULL);
	// ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	iswolf.resize(n + 1);
	howmuch.resize(n + 1);
	leafs.resize(n + 1);

	for(int i = 2; i <= n; i++) {
		char kind;
		ll value, parent;

		cin >> kind >> value >> parent;

		leafs[parent].push_back(i);
		howmuch[i] = value;
		iswolf[i] = (kind == 'W');
	}

	ll ans = dfs(1);
	cout << ans << "\n";

	return 0;
}