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

	int n, c3, c2;
	cin >> n;
	c3 = c2 = 0;
	for(int i = 0; i < n; i++) {
		int num; cin >> num;
		c2 += num / 2;
		c3 += num;
	}

	if(c3 % 3 != 0) {
		cout << "NO\n";
	} else {
		c3 = c3 / 3;
		if(c2 >= c3) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}