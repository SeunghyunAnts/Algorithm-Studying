/*
    BOJ 1300 (https://www.acmicpc.net/problem/1300)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k, score, left, right, maxSum = 0, ans = -1;
	vector<int> examPaper;

	// init
	{
		cin >> n >> k;
		for(int i = 0; i < n; i++) {
			cin >> score;
			examPaper.push_back(score);
			maxSum += score;
		}
		left = 0;
		right = maxSum;
	}

	// binary search
	while(left <= right) {
		// cur : min sum of scores
		int cur = (left + right) / 2;
		int rest = maxSum - cur;
		int curCnt = 0;
		int s = 0;

		// cout << left << " "<< right << " " <<  cur << "\n";

		for(int i = 0; i < n; i++) {
			s += examPaper[i];
			if(s >= cur) {
				s = 0;
				curCnt++;
			}
		}

		if(curCnt == k) {
			left = cur + 1;
			ans = cur;
		} else if(curCnt < k) {
			right = cur - 1;
		} else {
			// curCnt > k
			left = cur + 1;
		}
	}

	// output
	{
		cout << ans;
	}

	return 0;
}