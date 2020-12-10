#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, ans;
	cin >> n;
	int needs[n] = {0};
	for(int i = 0; i < n; i++) cin >> needs[i];
	sort(needs, needs + n);
	cin >> m;
	int le = 0, ri = needs[n - 1];
	while(le <= ri) {
		int mid = (le + ri) / 2;
		int cur = 0;

		for(int i = 0; i < n; i++) {
			if(needs[i] <= mid) {
				cur += needs[i];
			} else {
				cur += mid;
			}
		}

		if(cur <= m) {
			ans = mid;
			le = mid + 1;
		} else {
			ri = mid - 1;
		}
	}
	cout << ans;
	return 0;
}