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
		int n, ans = 0; cin >> n;
		int arr[n];
		bool isSpecial[8000 + 1] = {false};
		int secsum[n + 1] = {0};
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
			if(i == 0) secsum[i] = arr[i];
			else secsum[i] = secsum[i - 1] + arr[i];
		}

		for(int l = 0; l < n; l++) {
			for(int r = l + 1; r < n; r++) {
				int stt, dst;
				if(l == 0) stt = 0;
				else stt = secsum[l - 1];
				dst = secsum[r];
				if(dst - stt <= 8000) isSpecial[dst - stt] = true;
			}
		}

		for(int i = 0; i < n; i++) {
			if(isSpecial[arr[i]]) ans++;
		}

		cout << ans << "\n";
	}

	return 0;
}