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
		int n;
		cin >> n;
		bool check[2 * n + 1] = {false};
		for(int i = 0; i < 2 * n; i++) {
			int num;
			cin >> num;
			if(!check[num]) {
				cout << num << " ";
				check[num] = true;
			}
		}
		cout << "\n";
	}

	return 0;
}