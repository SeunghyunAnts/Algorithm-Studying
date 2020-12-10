#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while(tc--) {
		int n;
		cin >> n;

		if(n == 1) {
			cout << "0";
		} else if(n % 3 != 0) {
			cout << "-1";
		} else {
			int thrcnt = 0;
			while(n % 3 == 0) {
				n /= 3;
				thrcnt++;
			}
			if(!POW2(n)) {
				cout << "-1";
			} else {
				int twocnt = 0;
				while(n % 2 == 0) {
					n /= 2;
					twocnt++;
				}
				if(thrcnt < twocnt || 1 < n) {
					cout << "-1";
				} else {
					cout << (thrcnt - twocnt) + thrcnt;
				}
			}
		}
		cout << "\n";
	}

	return 0;
}