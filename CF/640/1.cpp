#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	string n;
	cin >> tc;

	while(tc--) {
		cin >> n;
		
		int cnt = 0;
		for(int i = 0; i < n.size(); i++) {
			if(n[i] != '0') cnt++;
		}

		cout << cnt << "\n";

		for(int i = 0; i < n.size(); i++) {
			if(n[i] != '0') {
				cout << n[i];
				for(int j = 0; j < n.size() - i - 1; j++) cout << "0";
				cout << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}