#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, s;
	int div;
	int divcnt = 0;
	int divpcnt = 0;

	cin >> n >> s;

	div = s / n;
	divcnt = n;
	s = s % n;
	divpcnt = s;

	if(div == 1) cout << "NO";
	else {
		cout << "YES\n";
		for(int i = 0; i < divcnt - divpcnt; i++) {
			cout << div << " ";
		}
		for(int i = 0; i < divpcnt; i++) {
			cout << div + 1 << " ";
		}
		cout << "\n1";
	}
	cout << "\n";

	return 0;
}