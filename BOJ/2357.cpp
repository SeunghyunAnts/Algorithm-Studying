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

// (ll, ll) 페어
#define pll pair<ll, ll>

int n, m;
vector<ll> arr;
vector<pll> segT;

pll init_segT(int idx, int start, int end) {
	if(start == end) {
		return segT[idx] = mp(arr[start], arr[start]);
	}

	int mid = (start + end) / 2;
	pll l = init_segT(2 * idx, start, mid);
	pll r = init_segT(2 * idx + 1, mid + 1, end);
	return segT[idx] = mp(max(l.first, r.first), min(l.second, r.second));
}

pll seg_mm(int idx, int start, int end, int le, int ri) {
	if(ri < start || end < le) {
		return mp((ll)0, (ll)1000000000 + 1);
	}

	if(le <= start && end <= ri) {
		return segT[idx];
	}

	int mid = (start + end) / 2;
	pll l = seg_mm(2 * idx, start, mid, le, ri);
	pll r = seg_mm(2 * idx + 1, mid + 1, end, le, ri);

	return mp(max(l.first, r.first), min(l.second, r.second));
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	arr.resize(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int height = (int)ceil(log2(n));
	int segT_size = (1 << (height + 1)); 
	segT.resize(segT_size + 1);

	init_segT(1, 1, n);

	for(int i = 0; i < m; i++) {
		int le, ri;
		cin >> le >> ri;
		pll ans = seg_mm(1, 1, n, le, ri);
		cout << ans.second << " " << ans.first << "\n";
	}

	return 0;
}