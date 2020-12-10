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

	int n;
	cin >> n;

	vector<int> tree[n + 1];
	int parents[n + 1] = {0};
	bool isChecked[n + 1] = {false};

	stack<int> stk;

	for(int i = 0; i < n - 1; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		tree[n1].push_back(n2);
		tree[n2].push_back(n1);
	}

	stk.push(1);
	while(!stk.empty()) {
		int node = stk.top();
		stk.pop();
		isChecked[node] = true;

		for(int i = 0; i < tree[node].size(); i++) {
			int next = tree[node][i];
			if(!isChecked[next]) {
				parents[next] = node;
				stk.push(next);
			}
		}
	}

	for(int i = 2; i <= n; i++) {
		cout << parents[i] << "\n";
	}

	return 0;
}