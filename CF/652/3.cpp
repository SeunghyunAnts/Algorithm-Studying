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
		ll n, k, s = 0, ocnt = 0;
		cin >> n >> k;
		ll arr[n] = {0}, p[k] = {0};
		for(ll i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for(ll i = 0; i < k; i++) {
			cin >> p[i];
			if(p[i] == 1) ocnt++;
		}
		sort(arr, arr + n);
		sort(p, p + k, greater<>());
		ll le = 0, ri = n - 1, t = ocnt;
		while(t--) {
			s += arr[ri] * 2;
			ri--;
		}
		for(ll i = 0; i < k; i++) {
			if(p[i] == 1) break;
			s += arr[ri];
			s += arr[le];
			ri--;
			le += p[i] - 1;
		}
		cout << s << "\n";
	}
	
	return 0;
}