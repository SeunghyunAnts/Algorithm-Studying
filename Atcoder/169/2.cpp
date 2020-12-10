#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long double n, cur = 1, maxnum = 1000000000000000000;
	vector<long double> nums;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		long double num;
		cin >> num;
		if(num == 0) {
			cout << 0;
			return 0;
		}
		nums.push_back(num);
	}

	sort(nums.begin(), nums.end());

	for(int i = 0; i < n; i++) {
		if(nums[i] <= (maxnum / cur)) {
			cur *= nums[i];
		} else {
			cout << -1;
			return 0;
		}
	}
	
	cout << (long long)cur;

	return 0;
}