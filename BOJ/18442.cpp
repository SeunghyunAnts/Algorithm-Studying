/*
    BOJ 18442 (https://www.acmicpc.net/problem/1759)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll v, p, l;				// num of village, num of post, length of village
	ll temp, cnt, mincnt;
	ll minsum = (ll)pow(2,63);
	vector<ll> villages, posts;

	// init
	{
		cin >> v >> p >> l;
		cnt = mincnt = 0;

		for(int i = 0; i < v; i++) {
			cin >> temp;
			villages.push_back(temp);
			posts.push_back(0);
		}

		for(int i = 0; i < p; i++) {
			posts[v - 1 - i] = 1;
		}

		sort(posts.begin(), posts.end());
	}

	// calc
	do {
		ll cursum = 0;

		for(int i = 0; i < v; i++) {
			ll curdif = 0, mindif = (ll)pow(2,63);

			for(int j = 0; j < v; j++) {
				if(posts[j] == 1) {
					curdif = min((ll)abs(villages[i] - villages[j]), (ll)(l - abs(villages[i] - villages[j])));
					if(curdif < mindif) {
						mindif = curdif;
					}
				}
			}
			cursum += mindif;
		}
		// updating
		if(cursum <= minsum) {
			minsum = cursum;
			mincnt = cnt;
		}
		cnt++;
	} while(next_permutation(posts.begin(), posts.end()));

	sort(posts.begin(), posts.end());
	for(int i = 0; i < mincnt; i++) {
		next_permutation(posts.begin(), posts.end());
	}

	// output
	{
		cout << minsum << "\n";
		for(int i = 0; i < v; i++) {
			if(posts[i] == 1) {
				cout << villages[i];
				if(i != v - 1) cout << " ";
			}
		}
	}

	return 0;
}