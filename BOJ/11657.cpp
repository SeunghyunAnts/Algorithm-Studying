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

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	ll INF = 10000000000;
	cin >> n >> m;

	bool check[n + 1] = {false};
	vector<ll> dir(n + 1, INF);
	vector< vector<pii> > adj(n + 1);

	for(int i = 0; i < m; i++) {
		ll s, d, v;
		cin >> s >> d >> v;
		adj[s].push_back(mp(d, v));
	}


	dir[1] = 0;
	bool isCycle = false;

	for(int i = 0; i < n + 1; i++) {
		for(int cur = 1; cur <= n; cur++) {
			for(int comp = 0; comp < adj[cur].size(); comp++) {
				int next = adj[cur][comp].first;
				ll value = adj[cur][comp].second;

				if(dir[cur] != INF && dir[next] > dir[cur] + value) {
					dir[next] = dir[cur] + value;
					if(i == n) isCycle = true;
				}
			}
		}
	}

	if(isCycle) {
		cout << "-1\n";
	} else {
		for(int i = 2; i <= n; i++) {
			if(dir[i] == INF) cout << "-1\n";
			else cout << dir[i] << "\n";
		}
	}

	return 0;
}