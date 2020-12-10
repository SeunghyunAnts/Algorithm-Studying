#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수
ll n;
vector<ll> arr;

// f(d) : 일정한 거리가 d일때, 전봇대를 이동하는 횟수
ll f(ll d) {
	ll cnt = 0;
	for(ll i = 0; i < n; i++) {
		cnt += abs(arr[i] - i * d);
	}
	return cnt;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 0; i < n; i++) {
		ll temp; cin >> temp; arr.push_back(temp);
	}
	if(n == 1) {
		cout << "0";
		return 0;
	}

	// 삼분탐색
	ll le = 0, ri = (ll)(1e9 + 1);
	while(le + 2 < ri) {
		ll fst = (2 * le + ri) / 3, scd = (le + ri * 2) / 3;
		ll lo = f(fst), hi = f(scd);

		if(lo <= hi) {
			// lo와 hi 사이에 최솟값 있음
			ri = scd;
		} else {
			le = fst;
		}
	}

	ll ans = 100000000000000;
	
	for(ll i = le; i <= ri; i++) {
		ans = min(f(i), ans);
	}

	cout << ans << "\n";

	return 0;
}