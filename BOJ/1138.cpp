#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수
int n;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	int leftperson[n + 1] = {0};
	int solve[n] = {0};
	for(int i = 1; i <= n; i++) cin >> leftperson[i];
	for(int i = 0; i < n; i++) solve[i] = i + 1;

	do {
		bool ret = true;
		for(int i = 0; i < n; i++) {
			int bigcnt = 0;
			for(int j = 0; j < i; j++) {
				if(solve[i] < solve[j]) bigcnt++;
			}
			if(bigcnt == leftperson[solve[i]]) {
				ret = ret && true;
			} else {
				ret = ret && false;
			}
		}
		if(ret) {
			for(int i = 0; i < n; i++) {
				cout << solve[i] << " ";
			}
			break;
		}
	} while(next_permutation(solve, solve + n));

	return 0;
}