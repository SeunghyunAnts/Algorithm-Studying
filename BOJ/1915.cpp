/*
    BOJ 1915 (https://www.acmicpc.net/problem/1915)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n, m;

bool islange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < m;
}


int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int maxnum = -1;
	int arr[1000][1000] = {0};

	// init
	{
		cin >> n >> m;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}
	}

	// calc
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(arr[i][j] > maxnum) maxnum = arr[i][j];
			if(arr[i][j] == 0) continue;
			else {
				int left = arr[i][ j - 1];
				int up = arr[i - 1][ j];
				int leup = arr[i - 1][j - 1];

				if(i == 0 || j == 0) {
					// left / up / leup 없음.
					continue;
				}

				if(islange(i, j - 1) && islange(i - 1, j) && islange(i - 1, j - 1)) {
					// left / up / leup 있음
					if(left * up * leup != 0) {
						arr[i][j] = min(min(left, up), leup) + 1;
					}
				}
			}
		}
	}

	cout << maxnum;

	return 0;
}