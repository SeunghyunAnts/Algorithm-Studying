#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;

	vector<int> odd;
	vector<int> even;

	for(int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if(num % 2 == 0) {
			even.push_back(num);
		} else {
			odd.push_back(num);
		}
	}

	sort(even.begin(), even.end(), greater<>());
	sort(odd.begin(), odd.end(), greater<>());

	int s = 0;

	if(even.size() == odd.size()) {
		s = 0;
	} else if(even.size() > odd.size()) {
		for(int i = odd.size() + 1; i < even.size(); i++) {
			s += even[i];
		}
	} else {
		for(int i = even.size() + 1; i < odd.size(); i++) {
			s += odd[i];
		}
	}

	cout << s;

	return 0;
}