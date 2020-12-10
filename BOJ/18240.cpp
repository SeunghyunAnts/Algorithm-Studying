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

int cnt = 1;
vector<pii> node;			// 노드의 자식노드 저장
vector<int> ans;			// 각 노드번호마다의 값
vector< vector<int> > tree;	// 각 높이의 노드 번호를 순서대로 저장

void inorder(int curnode) {
	if(node[curnode].first != 0) inorder(node[curnode].first);
	ans[curnode] = cnt++;
	if(node[curnode].second != 0) inorder(node[curnode].second);
	return;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, flag = 0;
	cin >> n;

	node.resize(n + 1);
	ans.resize(n + 1);
	tree.resize(n + 1);
	
	tree[0].push_back(1);				// Root노드는 1번 노드

	for(int i = 2; i <= n; i++) {
		int cur_height, parent_node; // i번째 노드의 높이, 그 부모노드번호
		cin >> cur_height;

		if(tree[cur_height - 1].size() * 2 < tree[cur_height].size() + 1) {
			// 노드를 새로 추가했을 때 invalid
			flag = 1; break;
		} else {
			tree[cur_height].push_back(i);
		}

		int s = tree[cur_height].size() - 1;
		parent_node = s / 2;

		if(s % 2 == 0) {
			node[tree[cur_height - 1][parent_node]].first = i;
		} else {
			node[tree[cur_height - 1][parent_node]].second = i;
		}
	}

	if(flag) {
		cout << -1;
	} else {
		inorder(1);
		for(int i = 1; i <= n; i++) {
			cout << ans[i] << " ";
		}
	}

	return 0;
}