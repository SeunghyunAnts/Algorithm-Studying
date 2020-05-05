/*
    BOJ 1939 (https://www.acmicpc.net/problem/1939)
*/

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int cur;
bool isCheck[10000 + 1] = {0};
vector< vector< pair<int, int> > > adj(100000 + 1);


int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;			// num of islands, num of bridge
	int a, b, c;		// start bridge, destination bridge, mass limit
	int le, ri;			// for binary search
	int s, e;			// start/end island number
	int maxMass = -1;
	int ans = -1;

	// init
	{
		cin >> n >> m;
		for(int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			if(c > maxMass) maxMass = c;
			adj[a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
		}
		le = 1 - 1;
		ri = maxMass + 1;
		cin >> s >> e;
	}

	// calc
	while(le <= ri) {	// init as 0 ~ max + 1

		int mid = (le + ri) / 2;	// maximum mass
		// cout << "left, right ,mid : " << le << " " << ri << " " << mid << "\n";

		// dfs
		stack<int> stk;
		stk.push(s);
		memset(isCheck, false, sizeof(isCheck));
		bool canMove = false;
		while(!stk.empty()) {
			cur = stk.top();	// 출발지
			stk.pop();
			// cout << "cur : " << cur << "\n";

			if(cur == e) {
				canMove= true;
				break;
			}

			// init 
			isCheck[cur] = 1;

			for(int i = 0; i < adj[cur].size(); i++) {
				int dest = adj[cur][i].first;
				int thisMass = adj[cur][i].second;
				if(!isCheck[dest] && thisMass >= mid) {
					stk.push(dest);
				}
			}
		}

		if(canMove) {
			// can be more mass
			ans = mid;
			le = mid + 1;
		} else {
			ri = mid - 1;
		}
	}

	cout << ri;

	return 0;
}