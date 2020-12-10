/*
    BOJ 9205 (https://www.acmicpc.net/problem/9205)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// 빠른입출력
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc, n, x, y;

	cin >> tc;

	while(tc--) {
		// 편의점의 개수를 입력
		cin >> n;

		// 좌표를 저장
		vector<pair<int,int>> dir(n + 2, make_pair(0, 0));
		// 이동 가능한지 저장
		vector<vector<int>> adj(n + 2, vector<int>(n + 2, 0));
		
		// 좌표입력
		for(int i = 0; i < n + 2; i++) {
			cin >> x >> y;
			dir[i].first = x;
			dir[i].second = y;
		}

		// 각 정점에서 한번에 갈 수 있는지 확인
		for(int i = 0; i < n + 2; i++) {
			for(int j = 0; j < n + 2; j++) {
				if(abs(dir[i].first - dir[j].first) + abs(dir[i].second - dir[j].second) <= 1000) {
					// 맨해튼 거리가 1000 이하일 경우 이동가능
					adj[i][j] = adj[j][i] = 1;
				} else {
					// 그렇지 않으면 이동 불가능
					adj[i][j] = adj[j][i] = 0;
				}
			}
		}

		// 플로이드 와샬 알고리즘으로 모든 경로 확인
		for(int mid = 0; mid < n + 2; mid++) {
			for(int stt = 0; stt < n + 2; stt++) {
				for(int dest = 0; dest < n + 2; dest++) {
					if(adj[stt][mid] == 1 && adj[mid][dest] == 1) {
						// 시작-중간노드가 연결되어있고,
						// 중간-도착노드가 연결되어 있으면,
						// 시작-도착노드가 연결되어 있다고 판단가능
						adj[stt][dest] = adj[dest][stt] = 1;
					}
				}
			}
		}

		// 집-페스티벌 노드가 연결되어 있다면 happy를 출력.
		if(adj[0][n + 1]) cout << "happy\n";
		else cout << "sad\n";
	}

	return 0;
}