#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// // For fast IO
	// cin.tie(NULL);
	// ios_base::sync_with_stdio(false);
	int tc;

	cin >> tc;

	const double pi = 3.1415926535897;
	const double side = 1.0;
	const double hs = 0.5;

	while(tc--) {
		int n;

		cin >> n;

		double t = (tan(pi / (2 * n)));

		printf("%.9lf\n", sqrt(2) * hs / (tan(pi / (2 * n))));
	}

	return 0;
}