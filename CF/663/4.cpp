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

	int n, m, ans = 0;
	cin >> n >> m;

	vector<string> board;
	vector<string> reboard;
	vector<int> cnt1, cnt2;
	board.resize(n);
	cnt1.resize(n, 0);
	cnt2.resize(m, 0);

	for(int i = 0; i < n; i++) {
		cin >> board[i];
		for(int j = 0; j < board[i].size(); j++) {
			if(board[i][j] == '1') {
				cnt1[i]++;
			}
		}
	}

	for(int i = 0; i < m; i++) {
		string cur = "";
		for(int j = 0; j < n; j++) {
			cur += board[j][i];
		}
		reboard.push_back(cur);
		for(int j = 0; j < n; j++) {
			if(cur[j] == '1') cnt2[i]++;
		}
	}

	if(n == 1 || m == 1) {
		cout << 0 << "\n";
		return 0;
	} else if(n >= 4 && m >= 4) {
		cout << -1 << "\n";
		return 0;
	} else {
		if(n >= m) {
			// 세로로 긴 경우
			if(m == 2) {
				// 가로 두줄짜리 세로
				for(int i = 0; i < n - 1; i++) {
					int cur = cnt1[i];
					int next = cnt1[i + 1];
					
					if(cur == 0) {
						if(next == 1) {
							continue;
						} else {
							cnt1[i + 1] = 1;
							ans++;
						}
					} else if(cur == 1) {
						if(next % 2 == 0) {
							continue;
						} else {
							ans++;
							cnt1[i + 1] = 0;
						}
					} else {
						// cur == 2
						if(next == 1) {
							continue;
						} else {
							cnt1[i + 1] = 1;
							ans++;
						}
					}
				}
			} else if(m == 3) {
				// 가로 세줄짜리 세로
				for(int i = 0; i < n - 1; i++) {
					string cur = board[i];
					string next = board[i + 1];

					string comp1, comp2;

					if(cur == "000") {
						comp1 = "010";
						comp2 = "101";
						
					} else if(cur == "001") {
						comp1 = "100";
						comp2 = "011";

					} else if(cur == "010") {
						comp1 = "000";
						comp2 = "111";

					} else if(cur == "100") {
						comp1 = "110";
						comp2 = "001";

					} else if(cur == "011") {
						comp1 = "110";
						comp2 = "001";

					} else if(cur == "110") {
						comp1 = "011";
						comp2 = "100";

					} else if(cur == "101") {
						comp1 = "111";
						comp2 = "000";

					}else {
						// cur == "111";
						comp1 = "101";
						comp2 = "010";

					}

					if(next == comp1 || next == comp2) continue;

					int c1 = 0, c2 = 0;
					for(int i = 0; i < 3; i++) {
						if(next[i] != comp1[i]) c1++;
						if(next[i] != comp2[i]) c2++;
					}

					if(c1 <= c2) {
						board[i + 1] = comp1;
						ans += c1;
					} else {
						board[i + 1] = comp2;
						ans += c2;
					}
				}
			}
		} else {
			// 세로로 긴 경우
			if(n == 2) {
				// 세로 두줄짜리 세로
				for(int i = 0; i < m - 1; i++) {
					int cur = cnt2[i];
					int next = cnt2[i + 1];
					
					if(cur == 0) {
						if(next == 1) {
							continue;
						} else {
							cnt2[i + 1] = 1;
							ans++;
						}
					} else if(cur == 1) {
						if(next % 2 == 0) {
							continue;
						} else {
							ans++;
							cnt2[i + 1] = 0;
						}
					} else {
						// cur == 2
						if(next == 1) {
							continue;
						} else {
							cnt2[i + 1] = 1;
							ans++;
						}
					}
				}
			} else if(n == 3) {
				for(int i = 0; i < m - 1; i++) {
					string cur = reboard[i];
					string next = reboard[i + 1];
					string comp1, comp2;

					// cout << "c , n :" << cur << " " << next << "\n";

					if(cur == "000") {
						comp1 = "010";
						comp2 = "101";
						
					} else if(cur == "001") {
						comp1 = "100";
						comp2 = "011";

					} else if(cur == "010") {
						comp1 = "000";
						comp2 = "111";

					} else if(cur == "100") {
						comp1 = "110";
						comp2 = "001";

					} else if(cur == "011") {
						comp1 = "110";
						comp2 = "001";

					} else if(cur == "110") {
						comp1 = "011";
						comp2 = "100";

					} else if(cur == "101") {
						comp1 = "111";
						comp2 = "000";

					}else {
						// cur == "111";
						comp1 = "101";
						comp2 = "010";

					}

					if(next == comp1 || next == comp2) continue;

					int c1 = 0, c2 = 0;
					for(int i = 0; i < 3; i++) {
						if(next[i] != comp1[i]) c1++;
						if(next[i] != comp2[i]) c2++;
					}

					if(c1 <= c2) {
						reboard[i + 1] = comp1;
						ans += c1;
					} else {
						reboard[i + 1] = comp2;
						ans += c2;
					}
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}