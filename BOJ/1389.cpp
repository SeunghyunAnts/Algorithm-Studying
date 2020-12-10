/*
    BOJ 1389 (https://www.acmicpc.net/problem/1389)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// 유저의 수, 친구 관계의 수
	int n, m;

	// 무한대로 가정
	int INF = 100000000;

	// 관계가 가장 작은사람 번호, 그때의 개수
	int minPeople = 0, cnt = INF;

	// 유저끼리의 거리 배열
	vector<vector<int>> adj;

	// 입력
	cin >> n >> m;

	// 배열 생성
	adj = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));

	// 친구관계 (바로 이어져 있는 경우) 입력
	for(int i = 0; i < m; i++) {
		int stt, dest;
		cin >> stt >> dest;
		adj[stt][dest] = adj[dest][stt] = 1;
	}

	// 플로이드 와샬 알고리즘으로
	// 각 정점에서 다른 정점으로의 최단 거리를 계산
	for(int mid = 1; mid <= n; mid++) {
		for(int stt = 1; stt <= n; stt++) {
			for(int dest = 1; dest <= n; dest++) {
				if(adj[stt][mid] + adj[mid][dest] < adj[stt][dest]) {
					adj[stt][dest] = adj[stt][mid] + adj[mid][dest];
				}
			}
		}
	}

	// 관계가 가장 작은 사람을 계산
	for(int i = 1; i <= n; i++) {
		int cur = 0;
		for(int j = 1; j <= n; j++) {
			cur += adj[i][j];
		}
		if(cur < cnt) {
			cnt = cur;
			minPeople = i;
		} else if(cur == cnt) {
			// 가장 작은 사람이 여러명인 경우, 번호가 작은 사람을 출력
			minPeople = min(minPeople, i);
		}
	}

	// 출력
	cout << minPeople;

	return 0;
}