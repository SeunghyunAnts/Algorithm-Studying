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

	while(tc--) {
		int n, cnt = 1;

		string s;
		cin >> n;
		cin >> s;

		vector<int> ans(n, 0);
		int le, ri;
		le = ri = n / 2;

		while(0 <= le || ri < n) {
			// 왼쪽으로 이동
			int lestt = le;
			while(0 <= le - 1 && s[le] != s[le - 1]) {
				le--;
			}

			// 오른쪽으로 이동
			int ristt = ri;
			while(ri + 1 < n && s[ri] != s[ri + 1]) {
				ri++;
			}

			// cout << le << " " << lestt << " " << ri << " " << ristt << "\n";

			if(lestt == ristt) {
				// [le ~ lestt] V [ristt ~ ri] 범위는 같은 subseq.
				for(int i = le; i <= lestt; i++) {
					ans[i] = cnt;
				}

				for(int i = ristt; i <= ri; i++) {
					ans[i] = cnt;
				}
				cnt++;
			} else {
				if(0 <= le) {
					if(ri < n) {
						// 둘다 적용
						if(s[lestt] == s[ristt]) {
							// 끊어지는 경우
							// [le ~ lestt] V [ristt ~ ri] 범위는 같은 subseq.
							for(int i = le; i <= lestt; i++) {
								ans[i] = cnt;
							}
							cnt++;

							for(int i = ristt; i <= ri; i++) {
								ans[i] = cnt;
							}
							cnt++;
						} else {
							// 연결되는 경우
							// [le ~ lestt] V [ristt ~ ri] 범위는 같은 subseq.
							for(int i = le; i <= lestt; i++) {
								ans[i] = cnt;
							}

							for(int i = ristt; i <= ri; i++) {
								ans[i] = cnt;
							}
							cnt++;
						}
					} else {
						// 오른쪽 적용 X
						for(int i = le; i <= lestt; i++) {
							ans[i] = cnt;
						}
						cnt++;
					}
				} else {
					if(ri < n) {
						// 왼쪽 적용 X
						for(int i = ristt; i <= ri; i++) {
							ans[i] = cnt;
						}
						cnt++;
					} else {
						// 둘다 적용 X
						break;
					}
				}
			}

			le--;
			ri++;
		}

		cout << cnt - 1 << "\n";
		for(int i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}