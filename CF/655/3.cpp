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
		int n, cnt = 0;
		bool cur;
		cin >> n;
		ll arr[n + 1] = {0};
		bool okay[n + 1] = {false};
		for(int i = 1; i <= n; i++) {
			cin >> arr[i];
			if(i == 1) {
				cur = (arr[i] == i);
			} else {
				if(cur == (arr[i] == i)) {
					continue;
				} else {
					cnt++;
					cur = (arr[i] == i);
				}
			}
		}

		if(cur == false && cnt == 0) {
			cout << 1 << "\n";
		} else if(cnt > 2) {
			cout << 2 << "\n";
		} else {
			cout << cnt << "\n";
		}
	}

	return 0;
}