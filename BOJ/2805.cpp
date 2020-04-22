/*
    BOJ 2805 (https://www.acmicpc.net/problem/2805)
*/

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int n;
ll needTree, tree, maxHeight = -1;
vector<ll> treeHeight, sumHeight;

ll search(int startHeight, int endHeight) {
	ll curHeight = (startHeight + endHeight) / 2;
	ll curTree = sumHeight[n - 1];

	// trash code
	if(startHeight > endHeight) {
		curHeight = endHeight;
		for(int i = 0; i < n; i++) {
			if(treeHeight[i] < curHeight) {
				curTree -= treeHeight[i];
			} else {
				curTree -= (curHeight);
			}
		}
		if(curTree > needTree) {
			maxHeight = curHeight;
			return curTree;
		}
	}

	for(int i = 0; i < n; i++) {
		if(treeHeight[i] < curHeight) {
			curTree -= treeHeight[i];
		} else {
			curTree -= (curHeight);
		}
	}

	if(curTree == needTree) {
		maxHeight = curHeight;
		return curTree;
	} else if(curTree < needTree) {
		return search(startHeight, curHeight - 1);
	} else {
		return search(curHeight + 1, endHeight);
	}
}

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// init
	{
		cin >> n >> needTree;
		for(int i = 0; i < n; i++) {
			cin >> tree;
			treeHeight.push_back(tree);
		}
		sort(treeHeight.begin(), treeHeight.end());
		for(int i = 0; i < n; i++) {
			if(i == 0) sumHeight.push_back(treeHeight[0]);
			else sumHeight.push_back(sumHeight[i - 1] + treeHeight[i]);
		}
	}

	// calc
	search(0, treeHeight[n - 1]);

	// output
	{
		cout << maxHeight;
	}

	return 0;
}