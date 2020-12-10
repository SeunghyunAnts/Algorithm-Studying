#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while(tc--) {
		bool ret = true;
		int n, x, e, maxlen;
		cin >> n >> x;
		maxlen = n;
		int ssum[n + 1] = {0};
		for(int i = 1; i <= n; i++) {
			cin >> e;
			ssum[i] = ssum[i - 1] + e;
		}

		while(0 < maxlen && ret) {
			for(int i = 1; i < n + 1; i++) {
				if(n < (i + maxlen - 1)) break;
				int cursum = ssum[i + maxlen - 1] - ssum[i - 1];
				if(cursum % x != 0) {
					ret = false;
				}
			}
			if(ret) maxlen--;
		}
		
		if(maxlen == 0) {
			cout << -1 << "\n";
		} else {
			cout << maxlen << "\n";
		}
	}

	return 0;
}