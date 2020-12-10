#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수
int city, mincost = 1000000000;
int adj[10 + 1][10 + 1] = {0};
bool check[10 + 1] = {false};

// DFS함수
int dfs(int stt, int cur, int curcost, int curcity) {
	if(curcity == city && stt == cur) {
		// 순회 완료 (탈출조건)
		return curcost;
	}

	int m = 1000000000;

	for(int dst = 0; dst < city; dst++) {
		if(cur == dst) {
			// 자기자신으로는 이동 불가
			continue;
		} else if(!check[dst] && adj[cur][dst] != 0) {
			// 확인하지 않았고, 길이 있는 경우
			check[dst] = true;
			m = min(m, dfs(stt, dst, curcost + adj[cur][dst], curcity + 1));
			check[dst] = false;
		} else if(curcity == city - 1 && dst == stt && adj[cur][dst] != 0) {
			// 다른 모든 도시를 순회했고, 다시 출발지로 가는 길이 있는 경우
			m = min(m, dfs(stt, dst, curcost + adj[cur][dst], curcity + 1));
		} else if(curcity == city - 1 && dst == stt && adj[cur][dst] == 0) {
			// 다른 모든 도시를 순회했고, 다시 출발지로 가는 길이 없는 경우
			return 1000000000;
		}
	}

	return m;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> city;
	for(int i = 0; i < city; i++) {
		for(int j = 0; j < city; j++) {
			cin >> adj[i][j];
		}
	}

	// 모든 노드에 대해서, 각각을 시작 노드로 보고 완전탐색
	for(int stt = 0; stt < city; stt++) {
		memset(check, 0, sizeof(check));
		check[stt] = true;
		mincost = min(mincost, dfs(stt, stt, 0, 0));
	}

	cout << mincost;

	return 0;
}