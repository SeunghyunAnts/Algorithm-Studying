#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// For fast IO
	// cin.tie(NULL);
	// ios_base::sync_with_stdio(false);


	ll n;
	ll cnt = 0;
	int arr[100000 + 1] = {0};
	vector<ll> pnums;

	cin >> n;
	
	// 소수 찾기
	for(ll i = 2; i <= 100000 + 1; i++) {
		if(arr[i] != 0) continue;
		if(n % i == 0) pnums.push_back(i);
		for(ll j = 2; i * j <= 100000 + 1; j++) {
			arr[i * j] = 1;
		}
	}

	for(int i = 0; i < pnums.size(); i++) {
		ll p = pnums[i];
		ll cur = p;
		while(n % cur == 0) {
			n /= cur;
			cur *= p;
			cnt++;
		}
		while(n % p == 0) {
			n /= p;
		}
	}

	if(1 < n) {
		// 100000 + 1 보다 크거나 같은 값으로 곱해져 있음.
		for(ll i = 100000 + 1; i < 1000000 + 1 && 1 < n; i++) {
			while(n % i == 0) {
				n /= i;
				cnt++;
			}
		}
		if(1 < n) cnt++;	// n은 소수
	}

	cout << cnt;

	return 0;
}