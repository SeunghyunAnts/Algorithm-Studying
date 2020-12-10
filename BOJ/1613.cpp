/*
    BOJ 1613 (https://www.acmicpc.net/problem/1613)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;	// 사건의 개수
	int k;	// 사건의 전후 관계의 개수
	int s;	// 테스트 케이스 개수

	int bef, nxt;	// temp

	int adj[400 + 1][400 + 1];	// 사건의 전후관계
	memset(adj, 0, sizeof(adj));	// 0 : 전후 관계를 알 수 없음

	cin >> n >> k;

	while(k--) {
		cin >> nxt >> bef;

		adj[nxt][bef] = -1;	// nxt가 bef보다 먼저 일어남 (1)
		adj[bef][nxt] = 1;	// bef가 nxt보다 늦게 일어남 (-1)
	}

	// 플로이드 와샬 알고리즘
	for(int mid = 1; mid <= n; mid++) {
		for(int stt = 1; stt <= n; stt++) {
			for(int dst = 1; dst <= n; dst++) {
				if(adj[stt][mid] == -1 && adj[mid][dst] == -1) {
					// 순서 : stt - mid - dst인 경우
					adj[stt][dst] = -1;
					adj[dst][stt] =1;
				} else if(adj[stt][mid] == 1 && adj[mid][dst] == 1) {
					// 순서 : dst - mid - stt인 경ㅇ
					adj[stt][dst] = 1;
					adj[dst][stt] = -1;
				}
			}
		}
	}

	cin >> s;

	while(s--) {
		cin >> nxt >> bef;
		cout << adj[nxt][bef] << "\n";	// 사건의 전후관계 출력
	}

	return 0;
}