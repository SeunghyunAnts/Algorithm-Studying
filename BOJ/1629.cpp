#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수


// a^b mod c를 리턴하는 함수
ll solve(ll a, ll b, ll c) {
	// a^b mod c = ( (a mod c) * (a mod c) * ... * (a mod c) ) mod c
	//  		 = ( (a mod c)^(b/2) * (a mod c)^(b/2) ) mod c;
	ll amc = a % c;

	if(b == 1) {
		return amc;
	} else if(b % 2 == 0) {
		return ((solve(amc, b/2, c) % c) * (solve(amc, b/2, c) % c)) % c;
	} else {
		return ((amc * (solve(amc, b/2, c) % c)) % c * (solve(amc, b/2, c) % c)) % c;
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll a, b, c, ans;
	cin >> a >> b >> c;

	ans = solve(a, b, c);
	cout << ans;

	return 0;
}