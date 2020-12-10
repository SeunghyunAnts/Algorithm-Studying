/*
    BOJ 1956 (https://www.acmicpc.net/problem/1956)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// 무한대
	int INF = 100000000;

	// 마을의 개수, 도로의 개수
	int v, e;

	// 최소 사이클의 도로 길이의 합
	int minSum = INF;

	// 입력
	cin >> v >> e;

	// 정점간 거리를 기록해두는 벡터
	vector<vector<int>> map(v + 1, vector<int>(v + 1, INF));

	// 출발노드, 도착노드, 노드간 거리를 입력받고, 벡터에 저장
	for(int i = 0; i < e; i++) {
		int stt, dest, dist;
		cin >> stt >> dest >> dist;
		map[stt][dest] = dist;
	}

	// 플로이드 와샬 알고리즘으로
	// 각 노드간 (자신 - 자신 포함) 이동 거리 계산
	for(int mid = 1; mid <= v; mid++) {
		for(int stt = 1; stt <= v; stt++) {
			for(int dest = 1; dest <= v; dest++) {
				if(map[stt][mid] + map[mid][dest] < map[stt][dest]) {
					map[stt][dest] = map[stt][mid] + map[mid][dest];
				}
			}
		}
	}

	// 자기 자신으로의 경로 중 가장 짧은 경로를 계산
	for(int i = 1; i <= v; i++) {
		if(map[i][i] < minSum) {
			minSum = map[i][i];
		}
	}

	// 사이클이 불가능한 경우 -1, 그렇지 않으면 최소거리를 출력
	if(minSum == INF) cout << -1;
	else cout << minSum;

	return 0;
}