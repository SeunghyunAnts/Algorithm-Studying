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

ll kC3(ll k) {
	return (k) * (k - 1) * (k - 2) / 6;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ll nd = 0, nz = 0;
	int n;
	cin >> n;
	vector<int> tree[n + 1];
	vector<int> parent(n + 1, 0);
	vector<ll> nearnode(n + 1, 0);

	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
		nearnode[a]++;
		nearnode[b]++;
	}

	for(int i = 1; i <= n; i++) {
		if(nearnode[i] >= 3) {
			nz += kC3(nearnode[i]);
		}
	}

	queue<int> q;
	vector<bool> check(n + 1, false);

	q.push(1);

	while(!q.empty()) {
		int head = q.front();
		check[head] = true;
		q.pop();

		for(int i = 0; i < tree[head].size(); i++) {
			int nextnode = tree[head][i];
			if(!check[nextnode]) {
				q.push(nextnode);
				nd += (tree[head].size() - 1) * (tree[nextnode].size() - 1);
			}
		}
	}

	if(nd > 3 * nz) {
		cout << "D";
	} else if(nd < 3 * nz) {
		cout << "G";
	} else {
		cout << "DUDUDUNGA";
	}
	
	return 0;
}