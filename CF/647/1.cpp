#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while(tc--) {
		ll a, b, c, temp, cnt = 0;
		cin >> a >> b;
		if(a == b) {
			cout << "0\n";
			continue;
		}

		if(a > b) {
			if(a % b == 0 && POW2(a/b)) {
				c = log2(a/b);
			} else {
				cout << "-1\n";
				continue;
			}
		} else {
			if(b % a == 0 && POW2(b/a)) {
				c = log2(b/a);
			} else {
				cout << "-1\n";
				continue;
			}
		}
		
		if(0 < c / 3) {
			cnt += c / 3;
			c -= 3 * (c / 3);
		}
		if(0 < c / 2) {
			cnt += c/ 2;
			c -= 2 * (c / 2);
		}
		if(0 < c) cnt += c;
		
		cout << cnt << "\n";
	}

	return 0;
}