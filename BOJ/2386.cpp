/*
    BOJ 2386 (https://www.acmicpc.net/problem/2386)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while(true) {
		char alpha;
		string str;
		int cnt = 0;

		cin >> alpha;

		if(alpha == '#') break;

		getline(cin, str);

		for(int i = 0; i < str.size(); i++) {
			if(str[i] == alpha || str[i] + 32 == alpha) {
				cnt++;
			}
		}
		
		cout << alpha << " " << cnt << "\n";
	}

	return 0;
}