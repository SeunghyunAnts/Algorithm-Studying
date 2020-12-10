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

	int n, m, cnt = 0;
	map<string, int> dmp;
	vector<string> ans;
	cin >> n >> m;

	for(int i = 0; i < n; i++) {
		string name;
		cin >> name;
		dmp.insert(mp(name, 1));
	}

	for(int i = 0; i < m; i++) {
		string name;
		cin >> name;
		if(dmp.find(name) != dmp.end()) {
			ans.push_back(name);
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for(vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << "\n";
	}

	return 0;
}