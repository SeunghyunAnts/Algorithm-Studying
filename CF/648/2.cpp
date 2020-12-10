#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while(tc--) {
		int n, temp, zero = 0, one = 0, prev = 0;
		bool ans = true;
		cin >> n;
		vector<int> a;
		for(int i = 0; i < n; i++) {
			cin >> temp;
			a.push_back(temp);
			if(prev == 0) prev = temp;
			else {
				if(prev <= temp) {
					continue;
				} else {
					ans = false;
				}
			}
		}
		for(int i = 0; i < n; i++) {
			cin >> temp;
			if(temp == 1) one++;
			else zero++;
		}
		if(one * zero == 0) {
			if(ans) cout << "YES\n";
			else cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}

	return 0;
}