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
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++) cin >> arr[i];
		sort(arr, arr + n, greater<>());
		for(int i = 0; i < n; i++) cout << arr[i] << " ";
		cout << "\n";
	}

	return 0;
}