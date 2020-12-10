#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, num;
	int maxnum = 0;
	stack<int> idx;
	int stt = -1;
	int last = -1;

	cin >> n;
	
	int arr[n + 1] = {0};
	int numcnt[2 * 100000 + 1] = {0};

	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		numcnt[arr[i]]++;
		if(numcnt[arr[i]] > numcnt[maxnum]) {
			maxnum = arr[i];
		}
	}

	// cout << maxnum << " " << numcnt[maxnum] << "\n";	//ex : 6이 3개 있다.

	for(int i = 1; i <= n; i++) {
		if(arr[i] == maxnum) {
			idx.push(i);
			if(stt == -1) {
				stt = i;
				last = i;
			} else {
				last = i;
			}
		}
	}

	cout << n - numcnt[maxnum] << "\n";

	while(!idx.empty()) {
		int cur = idx.top();
		idx.pop();

		int next = cur - 1;

		if(next > 0 && arr[next] != maxnum) {
			idx.push(next);
			if(arr[next] > maxnum) {
				cout << 2 << " " << next << " " << cur << "\n";
			} else {
				cout << 1 << " " << next << " " << cur << "\n";
			}
			
			arr[next] = maxnum;
		}

		if(cur == last) {
			int next = cur + 1;
			if(next < n + 1) {
				idx.push(next);
				if(arr[next] > maxnum) {
					cout << 2 << " " << next << " " << cur << "\n";
				} else {
					cout << 1 << " " << next << " " << cur << "\n";
				}
				arr[next] = maxnum;
				last = next;
			}
		}
	}

	return 0;
}