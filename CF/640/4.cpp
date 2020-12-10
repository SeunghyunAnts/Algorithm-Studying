#include <bits/stdc++.h>

typedef long long ll;
using namespace std;


int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	int n;

	cin >> tc;
	
	while(tc--) {
		int candies[1000];
		int s[1000] = {0};
		cin >> n;
		int a = 0, b = 0, cnt = 0;		// alice, bob
		int ap = 0, bp = n;			// alice, bob
		int prev = -1;
		bool turn = true;	// true면 엘리스차례, false면 밥차례

		for(int i = 0; i < n; i++) {
			cin >> candies[i];
			if(i == 0) s[i] = candies[i];
			else s[i] = candies[i] + s[i - 1];
		}

		a += candies[0];
		prev = a;
		cnt++;
		turn = false;

		if(n == 1) {
			cout << cnt << " " << a << " " << 0 << "\n";
			continue;
		}

		// ap : 앨리스가 이미 "먹은" 포인터
		// bp : 밥이 이미 "먹은" 포인터
		while(ap < bp) {
			int curCandies = 0;
			if(turn) {
				// 앨리스차례
				while(curCandies <= prev) {
					ap++;
					if(ap >= bp) break;
					curCandies += candies[ap];
				}

				prev = curCandies;
				a += prev;
				cnt++;
				turn = !turn;
			} else {
				// 밥차례
				while(curCandies <= prev) {
					bp--;
					if(bp <= ap) break;
					curCandies += candies[bp];
				}

				prev = curCandies;
				b += prev;
				cnt++;
				turn = !turn;
			}
		}

		cout << cnt << " " << a << " " << b << "\n";


	}

	return 0;
}