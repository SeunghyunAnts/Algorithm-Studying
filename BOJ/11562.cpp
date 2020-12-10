/*
    BOJ 11562 (https://www.acmicpc.net/problem/11562)
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

	// 대학교 건물의 수, 길의 수, 질문의 수
	int n, m, k;
	
	// 입력
	cin >> n >> m;

	// 건물 간 길의 정보를 저장하는 벡터
	vector<vector<int>> map(n + 1, vector<int>(n + 1, 0));

	// 건물 간 이동하려면 바꿔야하는 길의 개수를 저장하는 벡터
	vector<vector<int>> changing(n + 1, vector<int>(n + 1, INF));

	// m개의 길의 수 입력
	for(int i = 0; i < m; i++) {
		int stt, dest, bnry;

		cin >> stt >> dest >> bnry;

		if(bnry == 0) {
			// 일방향 길인 경우
			map[stt][dest] = 1;
			changing[stt][dest] = 0;
			changing[dest][stt] = 1;
		} else {
			// 양방향 길인 경우
			map[stt][dest] = map[dest][stt] = 1;
			changing[stt][dest] = changing[dest][stt] = 0;
		}
	}

	for(int i = 1; i <= n; i++) {
		map[i][i] = 1;
		changing[i][i] = 0;
	}

	// 플로이드 와샬 알고리즘으로 현재 상태에서
	// 서로 도달 가능한 건물 확인
	for(int mid = 1; mid <= n; mid++) {
		for(int stt = 1; stt <= n; stt++) {
			for(int dest = 1; dest <= n; dest++) {
				if(map[stt][mid] && map[mid][dest]) {
					map[stt][dest] = 1;
					changing[stt][dest] = 0;
				} else if(map[stt][mid] && !map[mid][dest]) {
					map[stt][dest] = max(0, map[stt][dest]);
					changing[stt][dest] = min(changing[stt][dest], changing[mid][dest]);
				} else if(!map[stt][mid] && map[mid][dest]) {
					map[stt][dest] = max(0, map[stt][dest]);
					changing[stt][dest] = min(changing[stt][dest], changing[stt][mid]);
				} else if(!map[stt][mid] && !map[mid][dest]) {
					map[stt][dest] = max(0, map[stt][dest]);
					changing[stt][dest] = min(changing[stt][dest], changing[stt][mid] + changing[mid][dest]);
				}
			}
		}
	}


	// 질문의 수 입력
	cin >> k;

	// 질문
	while(k--) {
		int stt, dest;

		cin >> stt >> dest;

		cout << changing[stt][dest] << "\n";
	}

	return 0;
}