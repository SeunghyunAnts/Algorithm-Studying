#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n;

bool inRange(int y, int x) {
	return (1 <= y && y <= n && 1 <= x && x <= n);
}

int main(void) {
	// For fast IO
	// cin.tie(NULL);
	// ios_base::sync_with_stdio(false);

	int tc;

	// int dirx[8] = {1, 0, -1, -1, -1, 0, 1};
	// int diry[8] = {1, 1, 1, 0, -1, -1, -1};
	int dirx[2] = {1, 0};
	int diry[2] = {0, 1};

	scanf("%d", &tc);

	while(tc--) {
		bool ret = true;
		stack<pair<int,int>> stk;	// pair<y,x>, arr[y][x] == 1

		scanf("%d", &n);

		int p[50 + 1][50 + 1] = {0};

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				scanf("%1d", &p[i][j]);
				if(p[i][j] == 1) {
					stk.push(make_pair(i, j));
				}
			}
		}

		while(!stk.empty() && ret) {
			bool cur = false;
			int y = stk.top().first;
			int x = stk.top().second;

			stk.pop();

			for(int i = 0; i < 2; i++) {
				// right, down == 1 check
				int yy = y + diry[i];
				int xx = x + dirx[i];

				if(inRange(yy, xx)) {
					if(p[yy][xx] == 1) {
						cur = true;
					}
				} else if(xx == n + 1 || yy == n + 1) {
					cur = true;
				}
			}

			if(!cur) {
				ret = false;
			}

		}

		if(ret) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}