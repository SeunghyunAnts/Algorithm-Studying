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

	int tc, INF = 1000000000;
	cin >> tc;
	while(tc--) {
		int n, m, w, s, d, t;
		bool timeback = false;
		cin >> n >> m >> w;
		vector< pair<int, int> > adj[n + 1];
		for(int i = 0; i < m; i++) {
			cin >> s >> d >> t;
			adj[s].push_back(make_pair(d, t));
			adj[d].push_back(make_pair(s, t));
		}
		for(int i = 0; i < w; i++) {
			cin >> s >> d >> t;
			adj[s].push_back(make_pair(d, -(t)));
		}
		bool checked[n + 1] = {false};
		// 각각의 노드를 출발위치로 설정하여 이동
		for(int start = 1; start <= n && !timeback; start++) {
			if(checked[start]) continue;
			int dist[n + 1];
			bool mcycle = false;
			fill(dist, dist + n + 1, INF);
			dist[start] = 0;
			checked[start] = true;
			for(int i = 1; i <= n; i++) {
				// 벨만-포드 알고리즘 : (n - 1)회의 반복
				// 만약 n번째에 값이 갱신된다면 음의 싸이클이 존재함.
				for(int j = 1; j <= n; j++) {
					for(int k = 0; k < adj[j].size(); k++) {
						int next = adj[j][k].first;
						int d = adj[j][k].second;
						if(dist[j] != INF && dist[j] + d < dist[next]) {
							// 직선 거리가 있고, 최단 거리가 있다면 최신화
							dist[next] = dist[j] + d;
							if(i == n) mcycle = true;
							checked[next] = true;
						}
					}
				}
			}
			if(mcycle) {
				timeback = true;
			} else {
				continue;
			}
		}

		if(timeback) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}