#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

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
		int n, m;
		bool turn = true;
		cin >> n >> m;
		int block[50 + 1][50 + 1] = {0};
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin >> block[i][j];
				if(block[i][j] == 1) {
					block[i][0] = 1;
					block[0][j] = 1;
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(block[i][0] == 1 || block[0][j] == 1) continue;
				else {
					block[i][j] = 1;
					block[0][j] = 1;
					block[i][0] = 1;
					turn = !turn;
				}
			}
		}

		if(turn) {
			cout << "Vivek";
		} else {
			cout << "Ashish";
		}
		cout << "\n";
	}

	return 0;
}