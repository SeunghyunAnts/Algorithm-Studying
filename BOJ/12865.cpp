/*
    BOJ 12865 (https://www.acmicpc.net/problem/12865)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k, w, v;
	vector<pair<int,int>> t;
	int dp[100000 + 1][100 + 1] = {0};

	// init
	{
		cin >> n >> k;
		t.push_back(make_pair(-1, -1));	// 더미 입력
		for(int i = 0; i < n; i++) {
			cin >> w >> v;
			t.push_back(make_pair(w, v));
		}
		sort(t.begin(), t.end());	// 정렬
		// dp[0][x] = dp[y][x] = 0
	}

	// calc
	for(int i = 1; i <= k; i++) {
		// i만큼의 무게를 담을 수 있을 때,
		for(int j = 1; j <= n; j++) {
			// j번째 물건까지 담을수 있을 때의 최대 가치
			if(i >= t[j].second) {
				// i 무게에 j번째 물건을 담을 수 있는 경우
				dp[i][j] = max(dp[i][j - 1], dp[i - t[j].second][j - 1] + t[j].first);
			} else {
				// i < t[j].second
				// 이번 물건이 더 커서 넣을 수 없는 경우
				dp[i][j] = dp[i][j - 1];
			}
		}
	}

	for(int i = 1; i <= k; i++) {
		// i만큼의 무게를 담을 수 있을 때,
		for(int j = 1; j <= n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}

	cout << dp[k][n];

	return 0;
}