/*
    BOJ 5582 (https://www.acmicpc.net/problem/5582)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int lcs[4000 + 1][4000 + 1] = {0};

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s1, s2;

	int lsize = 0;

	cin >> s1 >> s2;
	int l1 = s1.size();
	int l2 = s2.size();

	for(int i = 0; i < l2 + 1; i++) {
		for(int j = 0; j < l1 + 1; j++) {
			// find lcs
			if(i == 0 || j == 0) {
				lcs[i][j] = 0;
				cout << lcs[i][j] << " ";
				continue;
			}

			if(s2[i - 1] == s1[j - 1]) {
				// 만약 같은 단어가 있는 경우
				if(lcs[i - 1][j - 1] == 0) {
					lcs[i][j] = 1;
				} else {
					lcs[i][j] = lcs[i - 1][j - 1] + 1;
				}
			}

			cout << lcs[i][j] << " ";

			if(lsize < lcs[i][j]) {
				lsize = lcs[i][j];
			}
		}
		cout << "\n";
	}

	cout << lsize;

	return 0;
}