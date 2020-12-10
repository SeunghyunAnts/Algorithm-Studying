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

	int n, m;
	cin >> n;
	queue<pii> q, qq;
	vector<int> adj[n + 1];
	vector<int> check(n + 1, -1);
	vector<pii> nearnode(n + 1, mp(0, 0));

	for(int i = 1; i <= n; i++) {
		int num;
		while(true) {
			cin >> num;
			if(!num) break;
			else {
				nearnode[i].first++;
				adj[i].push_back(num);
			}
		}
	}

	cin >> m;
	for(int i = 1; i <= m; i++) {
		int num; cin >> num;
		q.push(mp(num, 0));
		check[num] = 0;
	}

	while(!q.empty()) {
		while(!q.empty()) {
			int curnode = q.front().first;
			int curcnt = q.front().second;
			q.pop();
			for(int i = 0; i < adj[curnode].size(); i++) {
				int nextnode = adj[curnode][i];
				if(check[nextnode] == -1) {
					qq.push(mp(nextnode, curcnt + 1));
					nearnode[nextnode].second++;
				}
			}
		}

		while(!qq.empty()) {
			int curnode = qq.front().first;
			int curcnt = qq.front().second;
			qq.pop();
			if(check[curnode] == -1 && nearnode[curnode].second * 2 >= nearnode[curnode].first) {
				check[curnode] = curcnt;
				q.push(mp(curnode, curcnt));
			}
		}
	}

	for(int i = 1; i < check.size(); i++) {
		cout << check[i] << " ";;
	}

	return 0;
}