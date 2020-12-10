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

int root;
vector<int> pre_order_output;
vector<int> in_order_output;
vector<pii> tree(1000 + 1);

int make_tree(int idx_begin, int idx_end, int ptr) {
	int idx_parent;		// 부모노드의 인덱스
	int left, right;	// 부모노드 좌우측에 노드 개수

	if(idx_begin == idx_end) {
		cout << pre_order_output[ptr];
		return 0;
	}

	// 인덱스 찾기
	for(int i = idx_begin; i < idx_end; i++) {
		if(in_order_output[i] == pre_order_output[ptr]) {
			idx_parent = i;
			break;
		}
	}

	left = idx_parent - idx_begin;
	right = idx_end - idx_parent - 1;

	if(left && right) {
		make_tree(idx_begin, idx_parent, ptr + 1);
		make_tree(idx_parent + 1, idx_end, ptr + 1 + left);
	} else if(!left && right) {
		make_tree(idx_begin + 1, idx_end, ptr + 1);
	} else if(left && !right) {
		make_tree(idx_begin, idx_end - 1, ptr + 1);
	}

	cout << pre_order_output[ptr] << " ";
	return 0;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while(tc--) {
		int node_size;
		cin >> node_size;

		pre_order_output.clear();
		in_order_output.clear();
		tree.clear();

		{
			int num;
			for(int i = 0; i < node_size; i++) {
				cin >> num;
				pre_order_output.push_back(num);
			}
			for(int i = 0; i < node_size; i++) {
				cin >> num;
				in_order_output.push_back(num);
			}
		}

		make_tree(0, node_size, 0);
		cout << "\n";
	}

	

	return 0;
}