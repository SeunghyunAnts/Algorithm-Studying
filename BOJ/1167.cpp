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

/*

 백준 1167번

 입력
v : 정점의 개수
adj : 인접 리스트, adj[1] = <2,5> : 1에서 2로 가는 거리가 5

 알고리즘
이번에 새로 공부하게 된 알고리즘
임의의 한 정점에서 가장 먼 거리의 정점을 구하면, 그 정점은 트리의 지름을 이루는 두 노드 중 하나가 된다.
따라서 해당 노드에서 다시 가장 먼 정점을 구하면, 트리의 지름이 된다.

*/

int v;
bool check[100000 + 1];
vector<pii> adj[100000 + 1];

pii dfs(int cur, int difs) {
	int max_node_dif = 0, max_node = 0, node_cnt = 0;
	
	// 방문체크
	check[cur] = true;

	// 연결되어있는 방문하지 않은 모든 노드에 방문하여 최댓값을 찾음.
	for(int i = 0; i < adj[cur].size(); i++) {
		pii next = adj[cur][i];
		if(!check[next.first]) {
			node_cnt++;
			pii move_next = dfs(next.first, difs + next.second);
			if(max_node_dif < move_next.second) {
				max_node_dif = move_next.second;
				max_node = move_next.first;
			}
		}
	}

	if(node_cnt == 0) {
		return mp(cur, difs);
	} else {
		return mp(max_node, max_node_dif);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> v;

	for(int i = 0; i < v; i++) {
		int stt, dst, dist;
		cin >> stt >> dst;
		do {
			cin >> dist;
			adj[stt].push_back(mp(dst, dist));
			cin >> dst;
		} while(dst != -1);
	}

	pii le = dfs(1, 0);
	memset(check, 0, sizeof(check));
	pii ri = dfs(le.first, 0);

	cout << ri.second;

	return 0;
}