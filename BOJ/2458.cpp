/*
    BOJ 2458 (https://www.acmicpc.net/problem/2458)
*/

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(void) {
	// 빠른 입출력
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// 무한대
	int INF = 100000000;

	// 학생의 수, 키를 비교한 횟수, 자신의 키 순서를 아는 학생 수
	int n, m, cnt = 0;

	// 입력
	cin >> n >> m;

	// 키를 비교 가능한지 저장하는 벡터
	// map[a][b] : INF - a와 b의 키를 비교하지 못함.
	// map[a][b] : 0 - a가 b보다 키가 작음
	// map[a][b] : 1 - a가 b보다 키가 큼 
	vector<vector<int>> map(n + 1, vector<int>(n + 1, INF));

	// 학생 a, b를 입력받아서 비교한 정보를 저장
	// 번호가 a인 학생이 번호가 b인 학생보다 키가 작음
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 0;	// a가 b보다 키가 작음
		map[b][a] = 1;	// b가 a보다 키가 큼
	}

	// 플로이드 와샬 알고리즘으로 자기보다 키가 큰/작은 학생을
	// 구분할 수 있는지 확인
	for(int mid = 1; mid <= n; mid++) {
		for(int stt = 1; stt <= n; stt++) {
			for(int dest = 1; dest <= n; dest++) {
				if(map[stt][mid] == 0 && map[mid][dest] == 0) {
					// 시작노드가 중간노드보다 키가 작고,
					// 중간노드가 도착노드보다 키가 작다면
					// 시작노드가 도착노드보다 키가 작음
					map[stt][dest] = 0;
					map[dest][stt] = 1;
				} else if(map[stt][mid] == 1 && map[mid][dest] == 1) {
					// 시작노드가 중간노드보다 키가 크고,
					// 중간노드가 도착노드보다 키가 크다면
					// 시작노드가 도착노드보다 키가 큼
					map[stt][dest] = 1;
					map[dest][stt] = 0;
				}
			}
		}
	}

	// 자신의 키 순서를 알 수 있는 학생을 계산
	for(int i = 1; i <= n; i++) {
		bool cur = true;
		for(int j = 1; j <= n; j++) {
			if(map[i][j] == INF && i != j) {
				cur = false;
				break;
			}
		}
		if(cur) cnt++;
	}

	// 출력
	cout << cnt;

	return 0;
}