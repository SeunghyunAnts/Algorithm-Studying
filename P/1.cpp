#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;

	cin >> tc;

	while(tc--) {
		int n, cnt = 0;
		set<int> s;	// s에 값이 들어있으면, 이미 처리함
		cin >> n;
		int arr[n];
		memset(arr, 0, sizeof(arr));
		for(int i = 0; i < n; i++) cin >> arr[i];
		sort(arr, arr + n, greater<>());
		for(int i = 0; i < n; i++) {
			int cur = arr[i];
			if(s.find(cur) != s.end()) continue;
			else {
				s.insert(cur);
				if(cur % 2 == 0) {
					arr[i] = cur / 2;
					cnt++;
					i--;
				}
			}
		}
		cout << cnt << "\n";
	}


	return 0;
}