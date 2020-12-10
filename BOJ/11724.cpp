#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;

// 전역변수
stack<int> stk;
int n;
int arr[1000 + 1][1000 + 1] = {0};
int check[1000 + 1] = {0};

// node와 인접한 정점을 모두 탐색하고, check값을 true로 변경
int dfs(int node, int val) {
	check[node] = val;
	for(int i = 1; i <= n; i++) {
		if(!check[i] && arr[node][i]) {
			dfs(i, val);
		}
	}
	return val;
}

int find(void) {
	int cnt = 0;
	while(!stk.empty()) {
		int cur = stk.top();
		stk.pop();

		if(check[cur]) continue;

		// 이전에 탐색하지 않은 노드가 있으므로
		// 연결요소의 개수(cnt) 증가
		cnt++;
		dfs(cur, cnt);
	}
	return cnt;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int stt, dst;
		cin >> stt >> dst;
		arr[stt][dst] = arr[dst][stt] = 1;
	}

	for(int i = 1; i <= n; i++) stk.push(i);

	cout << find();

	return 0;
}