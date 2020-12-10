#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))
// int pair 간단히
#define pii pair<int, int>
#define mp(X, Y) make_pair(X, Y)

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수
int dp[100][10000 + 1];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, mincost = 10000 + 1;
	cin >> n >> m;

	vector<pii> apps(n);

	{
		for(int i = 0; i < n; i++) {
			cin >> apps[i].first;
		}
		for(int i = 0; i < n; i++) {
			cin >> apps[i].second;
		}
	}

	// dp[cur][i]
	// cur번째 앱까지 확인했을 때, 
	// i만큼의 코스트로 확보할 수 있는 최대 메모리 바이트
	for(int cur = 0; cur < n; cur++) {
		for(int i = 0; i < 10000 + 1; i++) {
			// <메모리, 비용>
			pii cur_app = apps[cur];

			// 초기값
			if(cur == 0) {
				if(i < cur_app.second) {
					dp[cur][i] = 0;
				} else {
					dp[cur][i] = cur_app.first;
				}
				continue;
			}
			
			if(i < cur_app.second) {
				dp[cur][i] = dp[cur - 1][i];
			} else {
				dp[cur][i] = max(cur_app.first + dp[cur - 1][i - cur_app.second], dp[cur - 1][i]);
			}

			if(m <= dp[cur][i]) {
				mincost = min(mincost, i);
			}
		}
	}

	cout << mincost;

	return 0;
}