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

	int n, p, t;
	cin >> n >> p >> t;
	queue<int> hands;
	for(int i = 1; i <= n; i++) {
		hands.push(i);
		hands.push(i);
	}

	int cur = 1;
	bool ans = false;
	bool up = true;
	for(int turn = 1; turn <= t; turn++) {
		for(int i = 0; i < cur; i++) {
			if(t == turn) {
				if(hands.front() == p) {
					ans = true; break;
				}
			}
			hands.push(hands.front());
			hands.pop();
		}

		if(cur == 1) {
			up = true;
		} else if(cur == 2 * n) {
			up = false;
		}

		if(up) cur++;
		else cur--;
	}

	if(ans) cout << "Dehet YeonJwaJe ^~^\n";
	else cout << "Hing...NoJam\n";

	return 0;
}