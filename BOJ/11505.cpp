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

int n, m, k;
ll moder = 1000000007;
vector<ll> arr, segT;

ll init_segT(int idx, int start, int end) {
	if(start == end) {
		return segT[idx] = arr[start] % moder;
	}

	int mid = (start + end) / 2;
	return segT[idx] = (init_segT(2 * idx, start, mid) * init_segT(2 * idx + 1, mid + 1, end)) % moder;
}

ll update(int idx, int start, int end, int c_idx, int c_value) {
	if(c_idx < start || end < c_idx) {
		// 범위 밖에 바뀐 원소가 있는 경우
		return segT[idx];
	}

	if(start == end) {
		// 바뀐 원소의 위치까지 온 경우
		return segT[idx] = arr[c_idx] = c_value % moder;
	}

	int mid = (start + end) / 2;

	return segT[idx] = ((update(2 * idx, start, mid, c_idx, c_value) % moder) * (update(2 * idx + 1, mid + 1, end, c_idx, c_value) % moder)) % moder;
}

ll seg_mult(int idx, int start, int end, int le, int ri) {
	if(ri < start || end < le) {
		// 구간이 겹치지 않는 경우
		return 1;
	}

	if(le <= start && end <= ri) {
		// 구간의 범위가 현재 범위보다 클 경우
		return segT[idx];
	}

	int mid = (start + end) / 2;
	return ((seg_mult(2 * idx, start, mid, le, ri) % moder) * seg_mult(2 * idx + 1, mid + 1, end, le, ri) % moder) % moder;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;
	arr.resize(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int height = (int)ceil(log2(n));
	int segT_size = (1 << (height + 1));
	segT.resize(segT_size + 1, 0);

	init_segT(1, 1, n);

	for(int i = 0; i < m + k; i++) {
		int order, b;
		ll c;
		cin >> order >> b >> c;
		if(order == 1) {
			update(1, 1, n, b, c);
		} else {
			cout << seg_mult(1, 1, n, b, c) << "\n";
		}
	}

	return 0;
}