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

	int n = 2500, m = 2500;
	for(int i = 0; i < 3; i++) {
		int b; cin >> b;
		n = min(n, b);
	}
	for(int i = 0; i < 2; i++) {
		int d; cin >> d;
		m = min(m, d);
	}

	cout << max(0, n + m - 50) << "\n";

	return 0;
}