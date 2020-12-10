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

int n, cnt = 0;
int check[25][25];
vector<string> m;
vector<int> ans;
stack<pii> stk;

bool inRange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < n;
}

int dfs(int y, int x, int val) {
	if(check[y][x] != -1) {
		return 0;
	} else {
		check[y][x] = val;
		
		for(int i = 0; i < 4; i++) {
			int yy = y + diry[i];
			int xx = x + dirx[i];

			if(inRange(yy, xx) && check[yy][xx] == -1 && m[yy][xx] == '1') {
				dfs(yy, xx, val);
			}
		}
	}
	return 0;
}


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(check, -1, sizeof(check));
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		m.push_back(s);
		for(int j = 0; j < n; j++) {
			if(s[j] == '1') stk.push(mp(i, j));
		}
	}

	while(!stk.empty()) {
		int y = stk.top().first;
		int x = stk.top().second;
		stk.pop();

		if(-1 < check[y][x]) {
			continue;
		} else {
			check[y][x] = cnt;
			cnt++;
		}

		for(int i = 0; i < 4; i++) {
			int yy = y + diry[i];
			int xx = x + dirx[i];

			if(inRange(yy, xx) && check[yy][xx] == -1 && m[yy][xx] == '1') {
				dfs(yy, xx, cnt - 1);
			}
		}
	}

	cout << cnt << "\n";
	for(int i = 0; i < cnt; i++) {
		ans.push_back(0);
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(check[i][j] != -1) {
				ans[check[i][j]]++;
			}
		}
	}
	sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}