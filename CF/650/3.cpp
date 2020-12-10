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
		int n, k, prev = -1, ans = 0, ocnt = 0;
		cin >> n >> k;
		
		string table; cin >> table;
		int difTable[n] = {0};
		for(int i = 0; i < n; i++) {
			if(table[i] == '1') {
				ocnt++;
				if(prev == -1) {
					prev = i;
					difTable[i] = i;
					ans += difTable[i] / (k + 1);
				} else {
					difTable[i] = i - (prev + 1);
					prev = i;
					ans += (difTable[i] - k) / (k + 1);
				}
			}
		}
		int temp = n - prev - 1;
		ans += temp / (k + 1);
		if(ocnt > 0) cout << ans << "\n";
		else {
			if(n % (k + 1) == 0) {
				cout << n / (k + 1) << "\n";
			} else {
				cout << n / (k + 1) + 1 << "\n";
			}
		}
	}

	return 0;
}