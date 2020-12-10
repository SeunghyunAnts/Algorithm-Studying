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
		int a, b, x, y, ans = 0;
		cin >> a >> b >> x >> y;
		ans = max( max(x*b, y*a), max((a - (x + 1))*b, (b - (y + 1)) * a));
		cout << ans << "\n";
	}
	
	return 0;
}