#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;	// <= 200

	cin >> tc;

	while(tc--) {
		int n;	// array a, b size
		int k;	// maximum change count

		cin >> n >> k;

		vector<int> a;	// array a
		vector<int> b;	// array b

		// array a input
		for(int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			a.push_back(tmp);
		}

		// array b input
		for(int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			b.push_back(tmp);
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int ap = 0;
		int bp = b.size() - 1;

		while(k--) {
			if(0 <= ap && ap < a.size() && 0 <= bp && bp < b.size()) {
				if(a[ap] < b[bp]) {
					// swap
					int tmp = a[ap];
					a[ap] = b[bp];
					b[bp] = a[ap];
					ap++;
					bp--;
				} else {
					break;
				}
			}
		}
		
		int s = 0;

		for(int i = 0; i < a.size(); i++) s += a[i];

		cout << s << "\n";
	}
	return 0;
}