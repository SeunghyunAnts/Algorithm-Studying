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

	int nodes, le = 1, ri, max_val = 0;
	vector<pii> adj[10000 + 1];
	bool check[10000 + 1] = {false};
	
	cin >> nodes;
	for(int i = 0; i < nodes - 1; i++) {
		int stt, dst, val;
		cin >> stt >> dst >> val;
		adj[stt].push_back(mp(dst, val));
		adj[dst].push_back(mp(stt, val));
	}

	queue<pii> q;
	q.push(mp(le, 0));

	while(!q.empty()) {
		int cur_node = q.front().first;
		int cur_value = q.front().second;

		if(max_val < cur_value) {
			max_val = cur_value;
			ri = cur_node;
		}
		check[cur_node] = true;
		q.pop();

		for(int i = 0; i < adj[cur_node].size(); i++) {
			int next_node = adj[cur_node][i].first;
			int next_value = adj[cur_node][i].second;
			if(!check[next_node]) {
				q.push(mp(next_node, cur_value + next_value));
			}
		}
	}

	memset(check, false, sizeof(check));
	q.push(mp(ri, 0));
	max_val = 0;

	while(!q.empty()) {
		int cur_node = q.front().first;
		int cur_value = q.front().second;

		if(max_val < cur_value) {
			max_val = cur_value;
			ri = cur_node;
		}
		check[cur_node] = true;
		q.pop();

		for(int i = 0; i < adj[cur_node].size(); i++) {
			int next_node = adj[cur_node][i].first;
			int next_value = adj[cur_node][i].second;
			if(!check[next_node]) {
				q.push(mp(next_node, cur_value + next_value));
			}
		}
	}
	
	cout << max_val;

	return 0;
}