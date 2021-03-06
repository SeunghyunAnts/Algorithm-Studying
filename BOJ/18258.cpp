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

ll dp[1000000 + 1] = {0};
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while(true) {
		int a, b;
		cin >> a >> b;
		if(a == b && a == 0) {
			break;
		}

		if(a > b) {
			if(a % b == 0) {
				cout << "multiple";
			} else {
				cout << "neither";
			}
		} else if(a == b) {
			cout << "factor";
		} else {
			if(b % a == 0) {
				cout << "factor";
			} else {
				cout << "neither";
			}
		}
		cout << "\n";
	}

	return 0;
}