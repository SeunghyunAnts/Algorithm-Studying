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

	int n, m;
	set<int> s;

	cin >> n;

	for(int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		s.insert(temp);
	}

	cin >> m;

	for(int i = 0; i < m; i++) {
		int cur;
		cin >> cur;
		if(s.find(cur) != s.end()) {
			cout << "1 ";
		} else {
			cout << "0 ";
		}
	}

	return 0;
}