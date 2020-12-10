#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	int alpha[26];

	while(tc--) {
		memset(alpha, 0, sizeof(alpha));
		int n, m;
		// memo[i][alpha] : i번째 인덱스(i = 1, 2, ...) 이하에서
		// alpha가 등장한 횟수를 저장.
		vector< vector<int> > memo;
		string s;

		cin >> n >> m;
		cin >> s;

		for(int i = 0; i <= n; i++) {
			vector<int> v(27);
			memo.push_back(v);
		}

		for(int i = 1; i <= n; i++) {
			int cur = s[i - 1] - 'a';
			if(i == 1) {
				memo[i][cur]++;
			} else {
				for(int j = 0; j < 26; j++) {
					memo[i][j] = memo[i - 1][j] + (int)(cur == j);
				}
			}
		}

		while(m--) {
			int temp;
			cin >> temp;
			memo[temp][26]++;
		}
		memo[n][26]++;

		for(int i = 0; i < s.size(); i++) {
			for(int j = 0; j < 26; j++) {
				alpha[j] += memo[i + 1][j] * memo[i + 1][26];
			}
		}

		for(int i = 0; i < 26; i++) {
			cout << alpha[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}