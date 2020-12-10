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

	int n, m, stt, dest;
	vector< map<int, int> > adj(1000 + 1);
	vector<int> dist(1000 + 1, 100000000);
	vector<bool> check(1000 + 1, false);
	priority_queue< pii, vector<pii>, greater<pii> > pq;

	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int s, d, v;
		cin >> s >> d >> v;
		pair<map<int, int>::iterator, bool> pib = adj[s].insert(mp(d, v));
		if(!pib.second) {
			adj[s][d] = min(adj[s][d], v);
		}
	}
	cin >> stt >> dest;

	dist[stt] = 0;
	pq.push(mp(0, stt));

	while(!pq.empty()) {
		int cur_dest = pq.top().second;
		int cur_val = pq.top().first;

		pq.pop();

		if(!check[cur_dest]) {
			check[cur_dest] = true;
		} else {
			continue;
		}

		for(auto i = adj[cur_dest].begin(); i != adj[cur_dest].end(); i++) {
			int next_dest = i->first;
			int next_val = i->second;
			if(cur_val + next_val < dist[next_dest]) {
				dist[next_dest] = cur_val + next_val;
				pq.push(mp(dist[next_dest], next_dest));
			}
		}
	}

	cout << dist[dest];

	return 0;
}