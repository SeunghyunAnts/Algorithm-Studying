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
		int n;
		cin >> n;
		ll bignum = 1000000000 + 1;
		ll cnt = 0, amin = bignum, bmin = bignum;
		vector<ll> a, b;
		for(int i = 0; i < n; i++) {
			ll num;
			cin >> num;
			a.push_back(num);
			if(num < amin) {
				amin = num;
			}
		}
		for(int i = 0; i < n; i++) {
			ll num;
			cin >> num;
			b.push_back(num);
			if(num < bmin) {
				bmin = num;
			}
		}

		for(int i = 0; i < n; i++) {
			ll difa = a[i] - amin;
			ll difb = b[i] - bmin;

			if(difa == difb) {
				cnt += difa;
			} else if(difa > difb) {
				cnt += difb;
				cnt += difa - difb;
			} else {
				cnt += difa;
				cnt += difb - difa;
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}