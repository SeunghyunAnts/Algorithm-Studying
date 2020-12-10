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
		int n;
		cin >> n;
		vector<int> ans;

		if(n < 4) {
			cout << -1 << "\n";
		} else {
			for(int i = n; 4 < i; i--) {
				if(i % 2 == 0) {
					cout << i << " ";
				}
			}
			cout << "2 4 ";
			for(int i = 1; i <= n; i++) {
				if(i % 2 != 0) {
					cout << i << " ";
				}
			}
			cout << "\n";
		}
	}

	return 0;
}