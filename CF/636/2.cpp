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
		int n;
		cin >> n;

		if((n/2) % 2 != 0) cout << "NO";
		else {
			cout << "YES\n";
			int cnt = n / 2;
			int cur = 2;
			int temp = -1;

			for(int i = 0; i < cnt; i++) {
				cout << cur << " ";
				if(i == cnt / 2) temp = cur;
				cur = cur + 2;
			}

			cur = 1;
			for(int i = 0; i < cnt / 2; i++) {
				cout << cur << " ";
				cur = cur + 2;
			}

			cur = temp + 1;
			for(int i = 0; i < cnt / 2; i++) {
				cout << cur << " ";
				cur = cur + 2;
			}
		}

		cout << "\n";
	}

	return 0;
}