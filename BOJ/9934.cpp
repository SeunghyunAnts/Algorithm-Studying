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
	// cin.tie(NULL);
	// ios_base::sync_with_stdio(false);

	int k, nodes;
	cin >> k;
	nodes = (int)pow(2, k) - 1;
	int cbt[nodes] = {0};
	vector<int> tree[k];
	
	for(int i = 0; i < nodes; i++) {
		cin >> cbt[i];
	}

	queue< pair<pii, int> > q;
	q.push(mp(mp(0, nodes - 1), 0));

	while(!q.empty()) {
		int le = q.front().first.first;
		int ri = q.front().first.second;
		int mid = (le + ri) / 2;
		int h = q.front().second;
		q.pop();

		if(le == ri) {
			tree[h].push_back(cbt[mid]);
		} else {
			q.push(mp(mp(le, mid - 1), h + 1));
			tree[h].push_back(cbt[mid]);
			q.push(mp(mp(mid + 1, ri), h + 1));
		}
	}

	for(int i = 0; i < k; i++) {
		for(int j = 0; j < tree[i].size(); j++) {
			cout << tree[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}