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

// 유효한 범위에 있는지 확인
bool inRange(int y, int x, int m, int n) {
	return (0 <= y && y < m && 0 <= x && x < n);
}

// 전역변수
int arr[50][50];
bool check[50][50];
stack<pii> stk;
int m, n, k, cnt;

int dfs(int y, int x) {
	check[y][x] = true;
	for(int i = 0; i < 4; i++) {
		int yy = y + diry[i];
		int xx = x + dirx[i];

		if(inRange(yy, xx, n, m) && !check[yy][xx] && arr[yy][xx] == 1) {
			dfs(yy, xx);
		}
	}

	return 0;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while(tc--) {
		cin >> m >> n >> k;
		memset(arr, 0, sizeof(arr));
		memset(check, false, sizeof(check));
		cnt = 0;

		while(k--) {
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
			stk.push(mp(y, x));
		}

		while(!stk.empty()) {
			int y = stk.top().first;
			int x = stk.top().second;
			stk.pop();

			if(check[y][x]) continue;
			else {
				cnt++;
				check[y][x] = true;
			}

			for(int i = 0; i < 4; i++) {
				int yy = y + diry[i];
				int xx = x + dirx[i];

				if(inRange(yy, xx, n, m) && !check[yy][xx] && arr[yy][xx] == 1) {
					dfs(yy, xx);
				}
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}