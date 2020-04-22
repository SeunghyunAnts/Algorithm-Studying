/*
    BOJ 1654 (https://www.acmicpc.net/problem/1654)
*/

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll maxLanSize = -1;
ll curLan, needLan, lan;
vector<ll> lanSize;

ll solve(ll minRange, ll maxRange) {
	ll midRange = (minRange + maxRange) / 2;
	ll curLanCnt = 0;

	if(minRange > maxRange || midRange == 0) return maxLanSize;

	for(int i = 0; i < curLan; i++) {
		curLanCnt += lanSize[i] / midRange;
	}

	if(curLanCnt == needLan) {
		if(maxLanSize < midRange) {
			maxLanSize = midRange;
		}
		return solve(midRange + 1, maxRange);
	} else if(curLanCnt < needLan) {
		return solve(minRange, midRange - 1);
	} else {
		if(maxLanSize < midRange) {
			maxLanSize = midRange;
		}
		return solve(midRange + 1, maxRange);
	}
}

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// init
	{
		cin >> curLan >> needLan;
		for(int i = 0; i < curLan; i++) {
			cin >> lan;
			lanSize.push_back(lan);
		}
	}

	// calc
	sort(lanSize.begin(), lanSize.end());
	solve(1, lanSize[curLan - 1]);

	// output
	{
		cout << maxLanSize;
	}

	return 0;
}