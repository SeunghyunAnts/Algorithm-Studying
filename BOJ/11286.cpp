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

	priority_queue<int> mpq;
	priority_queue< int, vector<int>, greater<int> > ppq;
	int n;
	cin >> n;

	while(n--) {
		int order;
		cin >> order;

		if(order == 0) {
			if(ppq.empty() && mpq.empty()) {
				cout << 0 << "\n";
			} else if(ppq.empty()) {
				cout << mpq.top() << "\n";
				mpq.pop();
			} else if(mpq.empty()) {
				cout << ppq.top() << "\n";
				ppq.pop();
			} else {
				if(abs(ppq.top()) < abs(mpq.top())) {
					cout << ppq.top() << "\n";
					ppq.pop();
				} else {
					cout << mpq.top() << "\n";
					mpq.pop();
				}
			}
		} else if(order < 0) {
			mpq.push(order);
		} else {
			ppq.push(order);
		}
	}

	return 0;
}