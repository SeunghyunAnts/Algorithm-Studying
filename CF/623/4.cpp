#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while(tc--) {
		int n;
		bool ret = true;
		cin >> n;
		int a[n];
		int b[2 * n + 1] = {0};
		vector<int> ans;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			b[a[i]] = 1;
		}
		for(int i = 0; i < n; i++) {
			int cur = a[i];
			bool can = false;
			ans.push_back(cur);
			for(int j = cur + 1; j < 2*n + 1; j++) {
				if(b[j] == 0) {
					b[j] = 1;
					can = true;
					ans.push_back(j);
					break;
				}
			}
			ret = ret && can;
		}
		if(ret) {
			for(int i = 0; i < ans.size(); i++) {
				cout << ans[i] << " ";
			}
		} else {
			cout << "-1";
		}
		cout << "\n";
	}
	
	return 0;
}