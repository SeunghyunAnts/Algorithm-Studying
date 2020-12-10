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

int n, m;
int adj[200 + 1][200 + 1];
int city[200 + 1];

int find_root_node(int cur_node) {
	if(cur_node == city[cur_node]) {
		return cur_node;
	} else {
		return city[cur_node] = find_root_node(city[cur_node]);
	}
}

void union_node(int node_x, int node_y) {
	// x의 자식노드가 y가 되도록 합침
	int x = find_root_node(node_x);
	int y = find_root_node(node_y);

	if(x < y) city[y] = x;
	else city[x] = y;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	memset(adj, -1, sizeof(adj));
	memset(city, -1, sizeof(city));

	for(int i = 1; i <= n; i++) {
		city[i] = i;
		for(int j = 1; j <= n; j++) {
			cin >> adj[i][j];
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(adj[i][j]) {
				union_node(i, j);
			}
		}
	}

	bool ans = true;
	int prev;
	for(int i = 0; i < m; i++) {
		int c;
		cin >> c;
		if(i == 0) prev = c;
		else {
			ans = ans && (city[prev] == city[c]);
			prev = c;
		} 
	}

	cout << (ans ? "YES\n" : "NO\n");

	return 0;
}