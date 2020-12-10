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
		int n, e = 0, o = 0, cnt = 0;
		cin >> n;
		int arr[2 * n + 1] = {0};
		vector<int> even;
		vector<int> odd;
		for(int i = 1; i < 2 * n + 1; i++) {
			cin >> arr[i];
			if(arr[i] % 2 == 0) {
				e++;
				even.push_back(i);
			} else {
				o--;
				odd.push_back(i);
			}
		}

		if(e == 0 || o == 0) {
			for(int i = 1; i <= n && cnt < n - 1; i++) {
				cout << 2 * i - 1 << " " << 2 * i << "\n";
				cnt++;
			}
		} else {
			for(int i = 0; i < even.size() / 2 && cnt < n - 1; i++) {
				cout << even[2 * i] << " " << even[2 * i + 1] << "\n";
				cnt++;
			}
			for(int j = 0; j < odd.size() / 2 && cnt < n - 1; j++) {
				cout << odd[2 * j] << " " << odd[2 * j + 1] << "\n";
				cnt++;
			}
		}
	}
	
	
	return 0;
}