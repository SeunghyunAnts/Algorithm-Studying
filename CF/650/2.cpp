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
		int n, ee = 0, oe = 0;
		cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
			if(i % 2 == 0 && arr[i] % 2 == 1) {
				ee++;
			} else if(i % 2 == 1 && arr[i] % 2 == 0) {
				oe++;
			}
		}
		if(ee == oe) {
			cout << ee << "\n";
		} else {
			cout << "-1\n";
		}
	}

	return 0;
}