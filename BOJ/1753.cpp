#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int v, e, stt, INF = 1000000000;
	cin >> v >> e;
	cin >> stt;
	vector< map<int,int> > adj(v + 1);
	vector<int> dist(v + 1, INF);	// stt에서 각 노드까지 거리
	dist[stt] = 0;	// 출발 노드

	// 경로를 입력
	for(int i = 0; i < e; i++) {
		int s, d, v;
		cin >> s >> d >> v;
		if(adj[s].find(d) != adj[s].end() && v < adj[s].find(d)->second) {
			// 기록된 길보다 짧은 길이 있는 경우
			adj[s][d] = v;
		} else if(adj[s].find(d) == adj[s].end()) {
			// 기록된 길이 없는 경우
			adj[s].insert(make_pair(d, v));
		}
	}

	// 노드 stt에서 가장 가까운 노드를 PQ에 입력
	// pair : (거리, 정점번호)
	priority_queue< pair<int, int>, vector< pair<int,int> >, greater< pair<int, int> > > pq;
	for(int i = 1; i < v + 1; i++) {
		pq.push(make_pair(dist[i], i));
	}

	// 방문한 노드인지 확인
	bool checked[v + 1] = {false};

	while(!pq.empty()) {
		int cur = pq.top().second;
		int d = pq.top().first;
		pq.pop();

		if(checked[cur]) continue;
		else checked[cur] = true;

		// cur에 연결된 노드 중 가까운 거리가 있으면 최신화
		map<int,int>::iterator it;
		for(it = adj[cur].begin(); it != adj[cur].end(); ++it) {
			int dest = it->first;
			int move = it->second;
			if(d + move < dist[dest]) {
				// 우회해서 이동하는 거리가 이전까지 최소거리보다 작을때
				dist[dest] = d + move;
				pq.push(make_pair(dist[dest], dest));
			}
		}
	}

	for(int i = 1; i < v + 1; i++) {
		if(dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}

	return 0;
}