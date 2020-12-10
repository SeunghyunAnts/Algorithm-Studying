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

	int tc;
	cin >> tc;

	while(tc--) {
		int n, m, cnt = 0;
		cin >> n >> m;
		
		vector<string> map;
		bool canmove[100 + 1][100 + 1] = {false};
		bool check[100 + 1][100 + 1] = {false};
		map.resize(n);

		for(int i = 0; i < n; i++) {
			cin >> map[i];
		}

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(j == m - 1) {
					if(i == n - 1) {
						continue;
					} else if(map[i][j] == 'R') {
						cnt++;
					}
				}

				if(i == n - 1) {
					if(j == m - 1) {
						continue;
					} else if(map[i][j] == 'D') {
						cnt++;
					}
				}
			}
			
		}
		cout << cnt << "\n";
	}

	return 0;
}