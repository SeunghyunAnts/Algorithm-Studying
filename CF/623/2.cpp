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
		int a, b, p;
		cin >> a >> b >> p;
		string s;
		cin >> s;
		ll ans = s.size();

		int le = 0, ri = s.size() - 1;
		while(le <= ri) {
			// 탑승하는 정류장의 위치
			int mid = (le + ri) / 2;
			// 이번 시행에서 사용하는 돈의 총액
			ll curpay = 0;
			// 현재 타고있는 이동수단
			char state = s[mid];

			if(state == 'A') {
				curpay = a;
			} else {
				curpay = b;
			}

			for(int i = mid + 1; i < s.size() - 1; i++) {
				if(state != s[i]) {
					// 갈아타야 함.
					state = s[i];
					if(state == 'A') {
						curpay += a;
					} else {
						curpay += b;
					}
				}
			}

			if(p < curpay) {
				le = mid + 1;
			} else {
				ans = min((ll)(mid + 1), ans);
				ri = mid - 1;
			}
		}

		cout << ans << "\n";
	}
	
	return 0;
}