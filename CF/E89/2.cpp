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
		int n, m, x;
		cin >> n >> m >> x;
		int le = m, ri = m;
		while(x--) {
			int l, r;
			cin >> l >> r;
			if(l <= le && ri <= r) {
				le = l;
				ri = r;
			} else if(ri < l || r < le || (le < l && r < ri)) continue;
			else if(l <= le && le <= r) {
				le = l;
			} else if(l <= ri && ri <= r) {
				ri = r;
			}
		}
		cout << ri - le + 1 << "\n";
	}

	return 0;
}