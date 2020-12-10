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
		int len = 200001;

		cin >> s;

		int ott[4] = {0};
		int fst = 0;
		int scd = 0;
		int thd = 0;
		int curlen = 0;
		for(int i = 0; i < s.size(); i++) {
			if(fst == 0) {
				fst = s[i] - '0';
				curlen = 1;
				continue;
			}
			int cur = s[i] - '0';

			if(cur == fst && scd == 0) {
				curlen = 1;
			} else if(cur == fst && scd != 0) {
				int temp = scd;
				scd = cur;
				fst = temp;
				curlen = 2;
			} else {
				if(scd == 0) {
					scd = cur;
					curlen = 2;
				} else {
					if(fst != cur && scd != cur) {
						thd = cur;
						curlen++;
						if(curlen < len) {
							len = curlen;
						}
						int temp = scd;
						scd = thd;
						fst = temp;
						curlen = 2;
					} else if(cur == scd) {
						curlen++;
					}
				}
			}
		}

		if(len != 200001) cout << len << "\n";
		else cout << 0 << "\n";
	}
	return 0;
}