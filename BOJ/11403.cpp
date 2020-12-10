/*
    BOJ 11403 (https://www.acmicpc.net/problem/11403)
*/

#include <bits/stdc++.h>
#define INF 1000000

typedef long long ll;

using namespace std;

int main(void) {
	int n;				// 100 이하 자연수
	int adj[100][100];	// 인접 행렬

	// 입력
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> adj[i][j];
			if(adj[i][j] == 0) adj[i][j] = INF;
		}
	}

	// 플로이드 와샬 알고리즘
	for(int i = 0; i < n; i++) {			// 시작노드
		for(int j = 0; j < n; j++) {		// 중간노드
			for(int k = 0; k < n; k++) {	// 도착노드
				// cout << "s m d : " << i << " " << j << " " << k << "\n";
				// cout << adj[i][j] << " " << adj[j][k] << " " <<  adj[i][k] << " \n";
				if(adj[i][j] + adj[j][k] <= adj[i][k]) {
					// cout << "changed\n";
					adj[i][k] = adj[i][j] + adj[j][k];
				}
			}
		}
	}

	for(int i = 0; i < n; i++) {			// 시작노드
		for(int j = 0; j < n; j++) {		// 중간노드
			for(int k = 0; k < n; k++) {	// 도착노드
				// cout << "s m d : " << i << " " << j << " " << k << "\n";
				// cout << adj[i][j] << " " << adj[j][k] << " " <<  adj[i][k] << " \n";
				if(adj[i][j] + adj[j][k] <= adj[i][k]) {
					// cout << "changed\n";
					adj[i][k] = adj[i][j] + adj[j][k];
				}
			}
		}
	}

	// 출력
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(adj[i][j] == INF) cout << "0" << " ";
			else cout << "1" << " ";
		}
		cout << "\n";
	}

	return 0;
}