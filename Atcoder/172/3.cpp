#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수
ll n, m, k, ans = 0;
vector<ll> a, b;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;
	a.push_back(0);
	b.push_back(0);
	for(int i = 0; i < n; i++) {
		ll book;
		cin >> book;
		a.push_back(a[i] + book);
	}
	for(int i = 0; i < m; i++) {
		ll book;
		cin >> book;
		b.push_back(b[i] + book);
	}
	
	int le = 0, ri = n + m;
	while(le <= ri) {
		// 총 확인할 책의 권수
		int mid = (le + ri) / 2;
		// 만족하는지
		bool flag = false;
		// 각각의 책상에서 볼 책의 권수
		for(int ab = 0; ab <= mid; ab++) {
			int bb = mid - ab;
			if(n < ab || m < bb) continue;
			if(a[ab] + b[bb] <= k) {
				flag = true;
				break;
			}
		}
		if(flag) {
			ans = max(ans, (ll)mid);
			le = mid + 1;
		} else {
			ri = mid - 1;
		}
	}
	
	cout << ans;

	return 0;
}