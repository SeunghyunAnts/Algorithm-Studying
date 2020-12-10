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
		int n;
		int cur = 0;
		int dummy = 0;
		cin >> n;
		vector<int> arr;
		for(int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}
		sort(arr.begin(), arr.end());
		for(int i = 0; i < n; i++) {
			if(arr[i] <= cur + 1) {
				cur++;
				dummy = 0;
			} else {
				dummy++;
				if(arr[i] <= cur + dummy) {
					cur += dummy;
					dummy = 0;
				}
			}
		}
		cout << cur + 1 << "\n";
	}

	return 0;
}