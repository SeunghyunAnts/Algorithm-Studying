#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;

	cin >> tc;

	while(tc--) {
		int n, m, x, y;
		int xcnt = 0, ycnt = 0;
		string t;

		cin >> n >> m >> x >> y;

		for(int i = 0; i < n; i++) {
			cin >> t;
			if(m == 1 && t[0] == '.') {
				xcnt++;
				continue;
			}
			for(int j = 0; j < m; j++) {
				if(j == m - 1) {
					if(t[j] == '.') {
						xcnt++;
					} else {
						continue;
					}
				}
				else if(t[j] == '.') {
					if(t[j + 1] == '.') {
						// ".." 
						if(2 * x < y) {
							xcnt++;
						} else {
							ycnt++;
							j++;
						}
					} else {
						// ".*"
						xcnt++;
					}
				} else {
					continue;
				}
			}
		}

		cout << (x * xcnt + y * ycnt) << "\n";
	}

	return 0;
}