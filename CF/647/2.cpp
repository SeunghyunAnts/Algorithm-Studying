#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while(tc--) {
		int n, ans = 0;
		cin >> n;
		vector<int> arr, comp;
		for(int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}
		sort(arr.begin(), arr.end());
		for(int i = 1; i < 1024; i++) {
			comp = arr;
			for(int j = 0; j < arr.size(); j++) {
				comp[j] = comp[j] ^ i;
			}
			sort(comp.begin(), comp.end());
			if(comp == arr) {
				ans = i;
				break;
			}
		}
		if(ans == 0) {
			cout << "-1\n";
		} else {
			cout << ans << "\n";
		}
	}

	return 0;
}