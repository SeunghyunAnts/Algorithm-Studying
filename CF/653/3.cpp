#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while(tc--) {
		int n, cntl = 0, cntr = 0;
		string s;
		stack<bool> stkl, stkr;
		cin >> n >> s;
		for(int i = 0; i < n / 2; i++) {
			if(s[i] == '(') stkl.push(true);
			else if(s[i] == ')') {
				if(stkl.empty()) {
					cntl++;
				} else {
					stkl.pop();
				}
			}
		}
		for(int i = n - 1; n / 2 <= i; i--) {
			if(s[i] == ')') stkr.push(true);
			else if(s[i] == '(') {
				if(stkr.empty()) {
					cntr++;
				} else {
					stkr.pop();
				}
			}
		}
		cout << max(cntl, cntr) << "\n";
	}

	return 0;
}