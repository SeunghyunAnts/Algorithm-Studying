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
		string s;
		int alpha[26] = {0};
		
		cin >> s;

		int isstt = -1;
		int isend = -1;
		bool ret = true;

		for(int i = 0; i < s.size(); i++) {
			alpha[s[i] - 'a']++;
		}

		for(int i = 0; i < 26; i++) {
			if(alpha[i] > 1) {
				ret = false;
				break;
			}
			if(isstt == -1 && alpha[i] == 1) {
				isstt = i;
			} else if(isstt != -1 && alpha[i] == 0) {
				isend = i;
			} else if(isstt != -1 && isend != -1 && alpha[i] == 1) {
				ret = false;
				break;
			}
		}

		if(ret) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}