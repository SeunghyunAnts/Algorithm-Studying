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

	int n, r, d, c = 0;
	cin >> n;

	vector<int> connect[n];	// 연결된 자식노드 저장
	bool isChecked[n] = {false};
	stack<int> stk;

	for(int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if(p == -1) {
			r = i;
		} else {
			connect[p].push_back(i);
		}
	}
	cin >> d;
	isChecked[d] = true;
	stk.push(r);

	while(!stk.empty()) {
		int node = stk.top();
		stk.pop();
		if(!isChecked[node]) isChecked[node] = true;
		else continue;

		int cnt = 0;
		for(int i = 0; i < connect[node].size(); i++) {
			int next = connect[node][i];
			if(!isChecked[next]) {
				stk.push(next);
				cnt++;
			}
		}
		if(cnt == 0) c++;
	}

	cout << c;
	
	return 0;
}