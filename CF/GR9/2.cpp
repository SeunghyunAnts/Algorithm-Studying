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
		int n, m, num;
		cin >> n >> m;
		bool canSearch = true;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> num;
				if(4 < num) canSearch = false;
				else if(0 < num) {
					if(i == 0 || i == n - 1) {
						if(j == 0 || j == m - 1) {
							if(2 < num) canSearch = false;
						} else {
							if(3 < num) canSearch = false;
						}
					} else {
						if(j == 0 || j == m - 1) {
							if(3 < num) canSearch = false;
						}
					}
				}
			}
		}

		if(canSearch) {
			cout << "YES\n";
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					if(i == 0 || i == n - 1) {
						if(j == 0 || j == m - 1) {
							cout << 2 << " ";
						} else {
							cout << 3 << " ";
						}
					} else {
						if(j == 0 || j == m - 1) {
							cout << 3 << " ";
						} else {
							cout << 4 << " ";
						}
					}
				}
				cout << "\n";
			}
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}