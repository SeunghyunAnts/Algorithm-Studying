/*
    BOJ 14912 (https://www.acmicpc.net/problem/14912)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, d;	// 1 <= n <= 100,000, 1 <= d <= 9;
	int digit[10] = {0};

	cin >> n >> d;

	for(int i = 1; i <= n; i++) {
		string s = to_string(i);

		for(int j = 0; j < s.size(); j++) {
			int num = s[j] - '0';
			digit[num]++;
		}
	}

	cout << digit[d];

	return 0;
}