#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, num;
	int counter[2 * 100000 + 1] = {0};
	bool ret = true;
	int up = 0, down = 0;

	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> num;
		if(counter[num] == 0) {
			down++;
		}
		counter[num]++;
		if(counter[num] > 2) {
			ret = false;
			break;
		}
	}

	if(ret) {
		cout << "YES\n";
		cout << n - down << "\n";
		for(int i = 0; i < 2 * 100000 + 1; i++) {
			if(counter[i] == 2) {
				cout << i << " ";
				counter[i]--;
			}
		}

		cout << "\n" << down << "\n";
		for(int i = 2 * 100000; i >= 0; i--) {
			if(counter[i]) {
				cout << i << " ";
				counter[i]--;
			}
		}
		cout << "\n";
	} else {
		cout << "NO";
	}


	return 0;
}