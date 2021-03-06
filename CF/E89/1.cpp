#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

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

	while(tc--) {
		int stick, dia, ans = 0;
		cin >> stick >> dia;
		if(2 * stick < dia) {
			ans = stick;
		} else if(2 * dia < stick) {
			ans = dia;
		} else {
			ans = (stick + dia) / 3;
		}
		
		cout << ans << "\n";
	}

	return 0;
}