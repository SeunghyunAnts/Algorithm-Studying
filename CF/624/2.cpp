#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while(tc--) {
		int n, m;
		cin >> n >> m;
		int nums[n + 1] = {0};
		int pos[m] = {0};

		for(int i = 1; i < n + 1; i++) {
			cin >> nums[i];
		}
		for(int i = 0; i < m; i++) {
			cin >> pos[i];
		}

		sort(pos + 0, pos + m);

		int stt, end;
		stt = end = 0;
		for(int i = 0; i < m; i++) {
			if(stt == 0) {
				stt = end = pos[i];
			} else {
				// stt와 end에 값이 이미 있는 경우
				if(end + 1 == pos[i]) {
					end = pos[i];
				} else {
					sort(nums + stt, nums + end + 2);
					stt = end = pos[i];
				}
			}
		}

		sort(nums + stt, nums + end + 2);

		bool ret = true;
		for(int i = 1; i < n; i++) {
			if(nums[i] > nums[i + 1]) {
				ret = false;
				break;
			}
		}

		if(ret) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}

	}

	return 0;
}