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
	int n, cnt = 0, val;
	cin >> n;
	int ans[n + 1];	// ans[x] : x번 움직였을 때, 일치하는 개수
	int a[n] = {0};		// a[x] == 1 : x라는 숫자가 1번째 index에 있음

	for(int i = 0; i < n; i++) {
		cin >> val;
		a[val] = i;
	}

	memset(ans, 0, sizeof(ans));

	for(int i = 0; i < n; i++) {
		cin >> val;
		// cout << ans[i] << " " << i <<"\n";
		if(i == a[val]) {
			ans[0]++;
		} else if(i < a[val]) {
			// a에서 현재 bi의 값이 더 오른쪽에 있을 경우
			ans[a[val] - i]++;
		} else {
			// 더 왼쪽에 있을 경우
			int idx = n - i + a[val];
			ans[idx]++;
		}
	}

	int maxnum = 0;
	for(int i = 0; i <= n; i++) {
		if(maxnum < ans[i]) maxnum = ans[i];
	}
	cout << maxnum;

	return 0;
}