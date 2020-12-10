#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;

	cin >> tc;

	while(tc--) {
		int n, m, k;
		int res = -1;

		cin>> n >> m >> k;

		int pc = n / k;	// 한사람당가지는카드수 == 최대 조커 수
		
		if(m == pc) {
			res = m;
		} else if(m > pc) {
			// 1명이 pc개 조커를 가지고, n -1명이 m - pc개 조커를 균등하게 나눔.
			if(m - pc < k - 1) {
				if(m - pc == 0) {
					res = pc;
				} else {
					// 최대 1개씩 가짐
					res = pc - 1;
				}
			}
			else if((m - pc) % (k - 1) == 0) {
				// 정확히 엔빵가능 (1개이상씩)
				res = pc - (m - pc) / (k - 1);
			} else {
				res = pc - ((m - pc) / (k - 1) + 1);
			}
		} else {
			// m < pc
			res = m;
		}

		cout << res << "\n";
	}

	return 0;
}