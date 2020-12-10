#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while(tc--) {
		int a, b;
		cin >> a >> b;
		if(a == b) {
			cout << "0\n";
		} else if(a < b) {
			if((b - a) % 2 == 0) {
				cout << 2 << "\n";
			} else {
				cout << 1 << "\n";
			}
		} else {
			if((a - b) % 2 == 0) {
				cout << 1 << "\n";
			} else {
				cout << 2 << "\n";
			}
		}
		
	}

	return 0;
}