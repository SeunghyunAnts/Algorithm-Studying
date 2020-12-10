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

int n, m, LIMITNUM = 1000000000 + 1;
vector<int> arr, segTree;

int init_segTree(int idx, int start, int end) {
	if(start == end) return segTree[idx] = arr[start];

	int mid = (start + end) / 2;
	return segTree[idx] = min(init_segTree(2 * idx, start, mid), init_segTree(2 * idx + 1, mid + 1, end));
}

int update(int idx, int start, int end, int c_idx, int c_value) {
	if(c_idx < start || end < c_idx) {
		return segTree[idx];
	}

	if(start == end) {
		return segTree[idx] = arr[start] = c_value;
	}

	int mid = (start + end) / 2;
	return segTree[idx] = min(update(2 * idx, start, mid, c_idx, c_value), update(2 * idx + 1, mid + 1, end, c_idx, c_value));
}

int seg_min(int idx, int start, int end, int le, int ri) {
	if(ri < start || end < le) {
		return LIMITNUM;
	}

	if(le <= start && end <= ri) {
		return segTree[idx];
	}

	int mid = (start + end) / 2;
	return min(seg_min(2 * idx, start, mid, le, ri), seg_min(2 * idx + 1, mid + 1, end, le, ri));
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	
	int height = (int)ceil(log2(n));
	arr.resize(n + 1, 0);
	segTree.resize((1 << (height + 1)), 0);

	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	cin >> m;

	init_segTree(1, 1, n);

	for(int i = 0; i < m; i++) {
		int o, x, y;
		cin >> o >> x >> y;
		if(o == 1) {
			update(1, 1, n, x, y);
		} else {
			cout << seg_min(1, 1, n, x, y) << "\n";
		}
	}

	return 0;
}