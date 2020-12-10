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

	pii x[2] = {mp(0, 0), mp(0, 0)}, y[2] = {mp(0, 0), mp(0, 0)};
	for(int i = 0; i < 3; i++) {
		int xx, yy;
		cin >> xx >> yy;
		if(x[0].first == 0) {
			x[0].first = xx;
			x[0].second = 1;
		} else if(x[0].first == xx) {
			x[0].second++;
		} else if(x[1].first == xx) {
			x[1].second++;
		} else {
			x[1].first = xx;
			x[1].second = 1;
		}

		if(y[0].first == 0) {
			y[0].first = yy;
			y[0].second = 1;
		} else if(y[0].first == yy) {
			y[0].second++;
		} else if(y[1].first == yy) {
			y[1].second++;
		} else {
			y[1].first = yy;
			y[1].second = 1;
		}
	}

	if(x[0].second % 2 == 1) {
		cout << x[0].first << " ";
	} else {
		cout << x[1].first << " ";
	}

	if(y[0].second % 2 == 1) {
		cout << y[0].first << " ";
	} else {
		cout << y[1].first << " ";
	}

	return 0;
}