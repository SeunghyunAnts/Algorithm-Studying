/*
    BOJ 9251 (https://www.acmicpc.net/problem/9251)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s1, s2;
	int arr[1000 + 1][1000 + 1] = {0};

	// init
	{
		cin >> s1 >> s2;
	}

	for(int i = 1; i <= s1.size(); i++) {
		for(int j = 1; j <= s2.size(); j++) {
			int idx1 = i - 1;
			int idx2=  j - 1;
			if(s1[idx1] == s2[idx2]) {
				// 새로운 글자가 추가되었을때 그 글자가 같으면,
				// 추가하기 이전 LCS보다 1 추가해야 함
				arr[i][j] = arr[i - 1][j - 1] + 1;
			} else {
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}

	for(int i = 0; i < s1.size(); i++) {
		for(int j = 0; j < s2.size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}