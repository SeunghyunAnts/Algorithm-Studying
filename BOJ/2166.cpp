#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

int n;
pair<ll, ll> points[10000 + 1];

ll triSize(int p1, int p2, int p3) {
	ll ret = points[p1].first * points[p2].second - points[p2].first * points[p1].second;
	ret += points[p2].first * points[p3].second - points[p3].first * points[p2].second;
	ret += points[p3].first * points[p1].second - points[p1].first * points[p3].second;

	return abs(ret);
}

long double polygonSize() {
	ll ret = 0;

	for(int i = 1; i < n - 1; i++) {
		ret += triSize(0, i, i + 1);
	}

	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		points[i].first = x;
		points[i].second = y;
	}

	sort(points, points + n);

	ll ans = polygonSize();
	if(ans % 2 == 0) {
		cout << ans / 2 << ".0";
	} else {
		cout << ans / 2 << ".5";
	}

	return 0;
}