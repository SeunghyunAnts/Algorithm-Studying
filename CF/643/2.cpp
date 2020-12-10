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
		int n;	// young explorers

		cin >> n;

		int e[n + 1] = {0};
		int needs[n + 1] = {0};
		int t = 0;

		for(int i = 1; i <= n; i++) {
			cin >> e[i];
			needs[e[i]]++;
		}

		int curP = 0;
		int needP = 0;
		for(int i = 1; i <= n; i++) {

			t += needs[i] / i;
			needs[i] -= i * (needs[i] / i);

			if(needs[i] == 0) continue;

			// cout << "i, cur, need : " << i << " " << curP << " " << needP<<"\n";

			if(curP == 0 && needP == 0) {
				curP = needs[i];
				needP = i;
				needs[i] = 0;
				continue;
			}

			curP += needs[i];
			needP = i;
			
			if(needP <= curP) {
				t++;
				curP -= needP;
				if(curP == 0) needP = 0;
			}
		}

		// cout << "cur, need : " << curP << " " << needP<<"\n";

		cout << t << "\n";
	}

	return 0;
}