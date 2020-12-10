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
		int x, y, z, m;
		cin >> x >> y >> z;
		m = max(x, max(y, z));

		if(x == y && y == z) {
			cout << "YES\n";
			cout << x << " " << y << " " << z << "\n";
		} else if(x == y && y != z) {
			if(x == m) {
				cout << "YES\n";
				cout << x << " " << 1 << " " << z << "\n";
			} else {
				cout << "NO\n";
			}
		} else if(x != y && y == z) {
			if(z == m) {
				cout << "YES\n";
				cout << x << " " << 1 << " " << z << "\n";
			} else {
				cout << "NO\n";
			}
		} else if(x == z && z != y) {
			if(x == m) {
				cout << "YES\n";
				cout << 1 << " " << x << " " << y << "\n";
			} else {
				cout << "NO\n";
			}
		} else {
			cout << "NO\n";
		}
		
	}

	return 0;
}