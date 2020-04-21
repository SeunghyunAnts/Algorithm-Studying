/*
    BOJ 16943 (https://www.acmicpc.net/problem/16943)
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int minnum, b;
	string a;

	// init
	{
		cin >> a >> b;
		minnum = -1;
	}

	// calc
	sort(a.begin(), a.end());

	do {
		// a[0] != 0
		if(a[0] == '0') continue;
		
		// string -> int
		int cur = stoi(a);
		if(cur < b && cur > minnum) {
			minnum = cur;
		}
	} while(next_permutation(a.begin(), a.end()));
	// output
	{
		cout << minnum;
	}

	return 0;
}