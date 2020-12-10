#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	ll ans = (ll)(1e10);
	cin >> n >> m;
	ll arr[n] = {0};
	ll le = 1, ri = (ll)(1e12);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		if(le < arr[i]) le = arr[i];
	}
	le--;
	while(le <= ri) {
		// 이번 시행에서 블루레이의 크기
		ll mid = (le + ri) / 2;
		// 이번 시행에서 블루레이 개수, 현재까지 개수
		ll curcnt = 0, s = 0;
		// 이번 시행에서 최대합
		ll maxs = 0;

		// 앞에서부터 블루레이 개수 확인
		for(int i = 0; i < n; i++) {
			if(s + arr[i] <= mid) {
				s += arr[i];
			} else {
				// 더이상 강의를 담을 수 없을 때
				curcnt++;
				if(maxs < s) maxs = s;
				s = arr[i];
			}
		}

		// 남은게 있으면 다른 블루레이에 넣음
		if(0 < s) {
			curcnt++;
			if(maxs < s) maxs = s;
		}
		
		if(m < curcnt) {
			le = mid + 1;
		} else {
			if(maxs < ans) {
				ans = maxs;
			}
			ri = mid - 1;
		}
	}

	cout << ans;

	return 0;
}