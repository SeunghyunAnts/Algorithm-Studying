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

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	for(int x = -999; x < 1000; x++) {
		int ax = a * x, dx = d * x;
		if(b == 0 && e == 0) {
			if(ax == c && dx == f) {
				cout << x << " " << 0 << "\n";
			}
		} else if(b == 0 && e != 0) {
			if(ax == c && (f - dx) % e == 0 && abs((f - dx) / e) < 1000) {
				cout << x << " " << (f - dx) / e << "\n";
			}
		} else if(b != 0 && e == 0) {
			if((c - ax) % b == 0 && dx == f && abs((c - ax) / b) < 1000) {
				cout << x << " " << (c - ax) / b << "\n";
			}
		} else {
			if((c - ax) % b == 0 && (f - dx) % e == 0) {
				int ly = (c - ax) / b;
				int ry = (f - dx) / e;
				if(ly == ry && abs(ly) < 1000) {
					cout << x << " " << (c - ax) / b << "\n";
				}
			}
		}
		
	}

	return 0;
}