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

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, target = 0;
	cin >> n;
	vector< map<int, ll> > dp(n);

	for(int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if(i == 0) {
			dp[i].insert(mp(num, 1));
		} else if(i == n - 1) {
			target = num;
		} else {
			map<int, ll>::iterator it;
			for(it = dp[i - 1].begin(); it != dp[i - 1].end(); it++) {
				int prev_sum = it->first;
				ll prev_n = it->second;

				if(0 <= prev_sum + num && prev_sum + num <= 20) {
					auto f = dp[i].find(prev_sum + num);
					if(f == dp[i].end()) {
						dp[i].insert(mp(prev_sum + num, prev_n));
					} else {
						f->second += prev_n;
					}
				}
				if(0 <= prev_sum - num && prev_sum - num <= 20) {
					auto f = dp[i].find(prev_sum - num);
					if(f == dp[i].end()) {
						dp[i].insert(mp(prev_sum - num, prev_n));
					} else {
						f->second += prev_n;
					}
				}
			}
		}
	}

	// for(int i = 0; i < n; i++) {
	// 	map<int, ll> temp = dp[i];
	// 	cout << i << "\n";
	// 	for(auto it = temp.begin(); it != temp.end(); it++) {
	// 		cout << "(" << it->first << ", " << it->second << ")\n";
	// 	}
	// }
	if(dp[n - 2].find(target) == dp[n - 2].end()) {
		cout << "hi";
	} else {
		cout << dp[n - 2][target];
	}

	return 0;
}