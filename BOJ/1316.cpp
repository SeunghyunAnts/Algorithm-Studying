#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))
// int pair 간단히
#define pii pair<int, int>
#define mp(X, Y) make_pair(X, Y)

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int sum = 0;

	for(int i = 0; i < n; i++) {
		string s;
		bool checker[26] = {false};
		bool ret = true;
		cin >> s;
		char prev;
		for(int i = 0; i < s.size(); i++) {
			if(i == 0) {
				prev = s[i];
				checker[s[i] - 'a'] = true;
			} else if(checker[s[i] - 'a']) {
				if(prev == s[i]) {
					continue;
				} else {
					ret = false;
					break;
				}
			} else {
				prev = s[i];
				checker[s[i] - 'a'] = true;
			}
		}
		if(ret) sum++;
	}

	cout << sum;

	return 0;
}