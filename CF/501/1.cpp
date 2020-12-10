#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, cnt = 0;
	int arr[100 + 1] = {0};

	cin >> n >> m;

	while(n--) {
		int li, ri;
		cin >> li >> ri;
		for(int i = li; i <= ri; i++) {
			if(arr[i] == 0) {
				arr[i] = 1;
				cnt++;
			}
		}
	}

	cout << m - cnt << "\n";
	for(int i = 1; i <= m; i++) {
		if(arr[i] == 0) {
			cout << i << " ";
		}
	}
	cout << "\n";


	return 0;
}