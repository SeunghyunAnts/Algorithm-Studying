/*
    BOJ 1477 (https://www.acmicpc.net/problem/1477)
*/

#include <bits/stdc++.h>

using namespace std;

int curStop, newStop, lineSize;
vector<int> line, dif;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> curStop >> newStop >> lineSize;
	line.push_back(0);
	for(int i = 0; i < curStop; i++) {
		int s;
		cin >> s;
		line.push_back(s);
	}
	line.push_back(lineSize);

	sort(line.begin(), line.end());

	for(int i = 0; i < line.size() - 1; i++) {
		dif.push_back(line[i + 1] - line[i]);
	}
	
	int left = 0, right = lineSize;

	while(left <= right) {
		int mid = (left + right) / 2;
		int stopCnt = 0;
		
		for(int i = 0; i < dif.size(); i++) {
			if(dif[i] < mid) {
				continue;
			}

			int cur = line[i];

			stopCnt += dif[i] / mid;
			if(dif[i] % mid == 0) stopCnt--;
		}

		if(stopCnt == newStop) {
			right = mid - 1;
		} else if(stopCnt > newStop) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	cout << left;

	

	return 0;
}