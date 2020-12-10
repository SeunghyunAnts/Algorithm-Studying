#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, order;
	ll x, s = 0, xr = 0;

	cin >> m;

	while(m--) {
		cin >> order;
		switch (order)
		{
		case 1:
			cin >> x;
			s += x;
			xr ^= x;
			break;
		case 2:
			cin >> x;
			s -= x;
			xr ^= x;
			break;
		case 3:
			cout << s << "\n";
			break;
		case 4:
			cout << xr << "\n";
			break;
		}
	}

	return 0;
}