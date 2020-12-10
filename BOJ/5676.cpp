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

int init_segTree(vector<int> &arr, vector<int> &tree, int idx, int start, int end) {
	if(start == end) {
		return tree[idx] = arr[start];
	}

	int mid = (start + end) / 2;
	return tree[idx] = init_segTree(arr, tree, 2 * idx, start, mid) * init_segTree(arr, tree, 2 * idx + 1, mid + 1, end);
}

int update(vector<int> &arr, vector<int> &tree, int idx, int start, int end, int c_idx, int val) {
	if(c_idx < start || end < c_idx) {
		return tree[idx];
	}

	if(start == end) {
		return tree[idx] = arr[c_idx] = val;
	}

	int mid = (start + end) / 2;
	return tree[idx] = update(arr, tree, 2 * idx, start, mid, c_idx, val) * update(arr, tree, 2 * idx + 1, mid + 1, end, c_idx, val);
}

int seg_mult(vector<int> &arr, vector<int> &tree, int idx, int start, int end, int le, int ri) {
	if(ri < start || end < le) {
		return 1;
	}

	if(le <= start && end <= ri) {
		return tree[idx];
	}

	int mid = (start + end) / 2;
	return seg_mult(arr, tree, 2 * idx, start, mid, le, ri) * seg_mult(arr, tree, 2 * idx + 1, mid + 1, end, le, ri);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	while(cin >> n >> k) {
		vector<int> arr, segTree;
		arr.resize(n + 1);

		int height = (int)ceil(log2(n));
		segTree.resize((1 << (1 + height)) + 1);

		for(int i = 1; i <= n; i++) {
			int num;
			cin >> num;
			if(num > 0) arr[i] = 1;
			else if(num == 0) arr[i] = 0;
			else arr[i] = -1;
		}

		init_segTree(arr, segTree, 1, 1, n);

		for(int i = 0; i < k; i++) {
			char order;
			int x, y;
			cin >> order >> x >> y;
			if(order == 'C') {
				if(y > 0) y = 1;
				else if(y < 0) y = -1;
				arr[x] = y;
				update(arr, segTree, 1, 1, n, x, y);
			} else {
				int ans = seg_mult(arr,segTree, 1, 1, n, x, y);
				if(ans > 0) cout << "+";
				else if(ans < 0) cout << "-";
				else cout << "0";
			}
		}
		cout << "\n";
	}

	return 0;
}