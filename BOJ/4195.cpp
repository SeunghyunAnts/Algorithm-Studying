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

map<string, int> people;
vector<int> parent;
vector<int> network;
int cnt;

int find_parent(int node) {
	if(parent[node] == node) {
		return node;
	} else {
		return parent[node] = find_parent(parent[node]);
	}
}

int merge(string p1, string p2) {
	int i1 = find_parent(people.find(p1)->second);
	int i2 = find_parent(people.find(p2)->second);

	if(i1 == i2) {
		return network[i1];
	}

	if(network[i1] < network[i2]) {
		parent[i1] = i2;
	} else if(network[i1] == network[i2]) {
		if(p1 < p2) {
			parent[i2] = i1;
		} else {
			parent[i1] = i2;
		}
	} else {
		parent[i2] = i1;
	}
	
	return network[i1] = network[i2] = network[i1] + network[i2];
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while(tc--) {
		people.clear();
		parent.clear(); parent.push_back(-1);
		network.clear(); network.push_back(-1);
		cnt = 0;

		int f;
		cin >> f;

		string a, b;

		while(f--) {
			cin >> a >> b;
			
			if(people.count(a) == 0) {
				people.insert(mp(a, ++cnt));
				parent.push_back(cnt);
				network.push_back(1);
			}
			if(people.count(b) == 0) {
				people.insert(mp(b, ++cnt));
				parent.push_back(cnt);
				network.push_back(1);
			}
			
			int cur = merge(a, b);
			cout << cur << "\n";
			
		}
	}

	return 0;
}