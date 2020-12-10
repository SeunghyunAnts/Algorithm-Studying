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

	int dp[1000] = {0}, dpr[1000] = {0}, dpg[1000] = {0}, dpb[1000] = {0};
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		if(i == 0) {
			dpr[i] = r;
			dpg[i] = g;
			dpb[i] = b;
		} else {
			dpr[i] = min(dpg[i - 1], dpb[i - 1]) + r;
			dpg[i] = min(dpr[i - 1], dpb[i - 1]) + g;
			dpb[i] = min(dpr[i - 1], dpg[i - 1]) + b;
		}
		dp[i] = min(dpr[i], min(dpg[i], dpb[i]));
	}
	cout << dp[n - 1];

	return 0;
}