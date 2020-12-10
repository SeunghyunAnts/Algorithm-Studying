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

	int tc;
	cin >> tc;
	string order;
	int n;
	queue<int> q;

	while(tc--) {
		cin >> order;

		if(order == "push") {
			cin >> n;
			q.push(n);
		} else if(order == "pop") {
			if(q.empty()) {
				cout << "-1\n";
			} else {
				cout << q.front() << "\n";
				q.pop();
			}
		} else if(order == "size") {
			cout << q.size() << "\n";
		} else if(order == "empty") {
			if(q.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		} else if(order == "front") {
			if(q.empty()) {
				cout << "-1\n";
			} else {
				cout << q.front() << "\n";
			}
		} else {
			if(q.empty()) {
				cout << "-1\n";
			} else {
				cout << q.back() << "\n";
			}
		}
	}

	return 0;
}