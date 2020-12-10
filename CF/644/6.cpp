#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n;

bool inRange(int y, int x) {
	return (1 <= y && y <= n && 1 <= x && x <= n);
}

int main(void) {
	// For fast IO
	// cin.tie(NULL);
	// ios_base::sync_with_stdio(false);

	int tc;

	scanf("%d", &tc);
	// cin >> tc;

	while(tc--) {
		int n, m;
		bool ret = true;

		cin >> n >> m;
		
		vector<string> v;
		vector<int> dif;

		int fst = -1;
		int scd = -1;

		for(int i = 0; i < n; i++) {
			string s;
			cin >> s;
			v.push_back(s);
			if(i == 0) {
				dif.push_back(0);
			} else {
				int cnt = 0;
				for(int j = 0; j < m; j++) {
					if(v[0][j] != v[i][j]) {
						cnt++;
						if(fst == -1) {
							fst = j;
						} else if(scd == -1) {
							scd == j;
						}
					}
					if(j == m - 1 && scd == -1) {
						if(scd == -1) {
							fst = -1;
							scd = -1;
						}
					}
				}
				if(2 < cnt) {
					ret = false;
					break;
				} 
			}
		}

		if(!ret) {
			cout << "-1\n";
		} else {

		}
		
	}

	return 0;
}