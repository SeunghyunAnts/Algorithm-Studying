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

		vector<int> p;

		for(int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			p.push_back(temp);
		}

		sort(p.begin(), p.end());

		int prev = -1;
		int next = -1;

		int idx1 = -1;
		int idx2 = -1;
		int maxdif = 100000;

		for(int i = 0; i < n; i++) {
			int dif;
			if(prev == -1) {
				prev = p[i];
			} else {
				next = p[i];
				dif = next - prev;
				if(dif < maxdif) {
					idx1 = prev;
					idx2 = next;
					maxdif = dif;
				}
				prev = next;
			}
		}

		cout << maxdif << "\n";
	}

	return 0;
}