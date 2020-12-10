/*
    BOJ 1300 (https://www.acmicpc.net/problem/1300)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	int n, k;

	cin >> tc;

	while(tc--) {
		cin >> n >> k;

		if(n < k || (n % 2 != 0 && k % 2 == 0)) {
			// k가 n보다 크면 불가능, 홀수를 짝수개로 나누면 불가능
			cout << "NO\n";
		} else {
			// 나머지 케이스
			if(n % 2 ==0) {
				// n이 짝수면

				// k가 짝수면
				if(k % 2 == 0) {
					int cnt = 0;
					for(int i = 0; i < k - 1; i++) {
						n = n - 1;
						cnt++;
					}

					cout << "YES\n";
					for(int i = 0; i < cnt; i++) {
						cout << "1 ";
					}

					cout << n << "\n";
				} else {
					// k가 홀수면
					
					int cnt = 0;
					for(int i = 0; i < k - 1; i++) {
						n = n - 2;
						cnt++;
					}

					if(n <= 0) {
						cout << "NO\n";
						continue;
					}
					
					cout << "YES\n";
					for(int i = 0; i < cnt; i++) {
						cout << "2 ";
					}

					if(n != 0) cout << n;
					cout << "\n";
				}
			} else {
				cout << "YES\n";
				int cnt = 0;
				for(int i = 0; i < k - 1; i++) {
					n = n - 1;
					cnt++;
				}

				for(int i = 0; i < cnt; i++) {
					cout << "1 ";
				}

				if(n != 0) cout << n;
				cout << "\n";
			}
		}
	}

	return 0;
}