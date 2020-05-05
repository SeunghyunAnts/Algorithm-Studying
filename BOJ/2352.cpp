/*
    BOJ 2352 (https://www.acmicpc.net/problem/2352)
*/

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, le, ri, maxlen = -1;
	vector<int> adj;	// 연결된 간선
	vector<int> lis;	// LIS 벡터

	// init
	{
		cin >> n;
		le = 0, ri = n;
		adj.push_back(-1);
		for(int i = 1; i <= n; i++) {
			int temp;
			cin >> temp;
			adj.push_back(temp);
		}
		lis.push_back(-1);
	}

	// calc
	for(int i = 1; i <= n; i++) {
		// cout << "current " << i << " " << adj[i] <<"\n";
		// for(int k = 0; k < lis.size(); k++) {
		// 	cout << lis[k] << " ";
		// }
		// cout << "\n";
		if(*(lis.end()-1) < adj[i]) {
			lis.push_back(adj[i]);
		} else {
			if(lis.size() - 1 > maxlen) {
				maxlen = lis.size() - 1;
			}
			auto it = lower_bound(lis.begin() + 1, lis.end(), adj[i]);
			*it = adj[i];
		}
	}

	// output
	{
		cout << lis.size() - 1;
	}

	return 0;
}