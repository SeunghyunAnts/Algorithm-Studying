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

	int tc;
	cin >> tc;

	while(tc--) {
		int m, n, x, y, ans = -1;
		cin >> m >> n >> x >> y;

		int k = x;	// 0 * m + x
		int maxK = (m * n) / __gcd(m, n);

		do {
			if((k - y) % n == 0) {
				ans = k;
				break;
			} else {
				k += m;
			}
		} while(k <= maxK);

		cout << ans << "\n";
	}

	return 0;
}