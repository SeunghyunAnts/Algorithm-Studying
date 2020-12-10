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

int n, m;
vector<ll> arr, segT;

ll init_segT(int idx, int start, int end) {
	if(start == end) return segT[idx] = arr[start];

	int mid = (start + end) / 2;
	return segT[idx] = init_segT(2 * idx, start, mid) + init_segT(2 * idx + 1, mid + 1, end);
}

void update(int idx, int start, int end, int c_idx, int dif) {
	if(c_idx < start || end < c_idx) return;

	segT[idx] += dif;
	if(start == end) return;

	int mid = (start + end) / 2;
	update(2 * idx, start, mid, c_idx, dif);
	update(2 * idx + 1, mid + 1, end, c_idx, dif);

	return ;
}

ll seg_sum(int idx, int start, int end, int le, int ri) {
	if(ri < start || end < le) {
		return 0;
	}

	if(le <= start && end <= ri) {
		return segT[idx];
	}

	int mid = (start + end) / 2;
	return seg_sum(2 * idx, start, mid, le, ri) + seg_sum(2 * idx + 1, mid + 1, end, le, ri);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	arr.resize(n + 1, 0);
	segT.resize( (1 << ( (int)ceil(log2(n) + 1 ) )), 0);

	init_segT(1, 1, n);

	for(int i = 0; i < m; i++) {
		ll order, x, y;
		cin >> order >> x >> y;
		if(!order) {
			if(x > y) swap(x, y);
			cout << seg_sum(1, 1, n, x, y) << "\n";
		} else {
			update(1, 1, n, x, y - arr[x]);
			arr[x] = y;
		}
	}

	return 0;
}