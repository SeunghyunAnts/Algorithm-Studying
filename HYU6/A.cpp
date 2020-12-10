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

	int n, p = 0;

	cin >> n;
	stack<pii> task;

	for(int i = 1; i <= n; i++) {
		int order;
		cin >> order;
		if(order) {
			int point, t;
			cin >> point >> t;
			task.push(mp(point, t));
		}
		if(!task.empty()) {
			task.top().second--;
			if(task.top().second == 0) {
				p += task.top().first;
				task.pop();
			}
		}
	}

	cout << p << "\n";

	return 0;
}