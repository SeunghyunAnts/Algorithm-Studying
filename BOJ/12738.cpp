/*
    BOJ 12738 (https://www.acmicpc.net/problem/12738)
*/

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, temp;
	vector<int> v;
	vector<int> lis;

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	lis.push_back(-1000000001);

	for(int i = 0; i < n; i++) {
		int cur = v[i];
		if(cur > *(lis.end() - 1)) {
			lis.push_back(cur);
		} else {
			auto it = lower_bound(lis.begin(), lis.end(), cur);
			*it = cur;
		}
	}

	cout << lis.size() - 1;

	return 0;
}