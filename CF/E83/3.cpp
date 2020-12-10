#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while(tc--) {
		bool ret = true;
		ll n, k, ptr = 0;
		vector<ll> pk;	// pk[ptr] = k*ptr
		cin >> n >> k;
		ll arr[n] = {0};
		for(ll i = 0; i < n; i++) cin >> arr[i];
		for(int i = 0, cur = 1; i < 100; i++) {
			pk.push_back(cur);
			cur *= k;
			if(10000000000000000 < cur) break;
		}
		sort(arr, arr + n);
		
		for(ll i = 0; i < n; i++) {
			if(arr[i] == 0) {
				continue;
			} else if(arr[i] % k != 0) {
				if(arr[i] == 1) {
					if(0 < ptr) {ret = false; break;}
					else {
						ptr++;
					}
				} else {
					ll cur = arr[i] - 1;
					if(cur % k == 0) {
						if(0 < ptr) {ret = false; break;}
						else {
							
						}
					} else {ret = false; break;}
				}
			}
		}

		cout << (ret ? "YES\n" : "NO\n");
	}

	return 0;
}