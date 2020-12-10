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

	string s;
	cin >> s;

	bool flag = true;

	int le = 0, ri = s.size() - 1;
	while(le <= ri) {
		if(s[le] == s[ri]) {
			le++; ri--;
		} else {
			flag = false;
			break;
		}
	}

	if(flag) cout << 1;
	else cout << 0;

	return 0;
}