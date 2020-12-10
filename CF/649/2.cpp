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

	int tc;
	cin >> tc;

	while(tc--) {
		ll n, k = 0;
		cin >> n;
		ll arr[n] = {0};
		vector<ll> ans;
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		bool up = true;
		int stt = 0, prev = -1;
		ans.push_back(0);
		for(int i = 1; i < n; i++) {
			if(i == 1) {
				if(arr[stt] < arr[i]) {
					up = true;
					prev = i;
				} else {
					up = false;
					prev = i;
				}
			} else {
				if(arr[prev] < arr[i]) {
					if(up) {
						prev = i;
					} else {
						k += abs(arr[prev] - arr[stt]);
						ans.push_back(prev);
						stt = prev;
						prev = i;
						up = true;
					}
				} else {
					if(!up) {
						prev = i;
					} else {
						k += abs(arr[prev] - arr[stt]);
						ans.push_back(prev);
						stt = prev;
						prev = i;
						up = false;
					}
				}
			}

			if(i == n - 1) {
				k += abs(arr[stt] - arr[i]);
				ans.push_back(i);
			}
		}

		// cout << k << "\n";
		cout << ans.size() << "\n";
		for(int i = 0; i < ans.size(); i++) {
			cout << arr[ans[i]] << " ";
		}
		cout << "\n";
	}

	return 0;
}