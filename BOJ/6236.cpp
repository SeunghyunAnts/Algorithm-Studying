/*
    BOJ 1956 (https://www.acmicpc.net/problem/6236)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k = -1;	// n일동안 m번만 출금, 출력할 값(최소 금액)
	ll le, ri;			// 이분탐색을 위한 변수
	vector<ll> money;	// n일 각각에서 사용해야 할 금액

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		ll day;
		cin >> day;
		money.push_back(day);
	}

	le = 1, ri = 1000000000;	// 최대 만원이 십만번 입력 가능

	while(le <= ri) {
		bool isover = false;	// 최대 금액으로도 하루를 사용하지 못하는경우
		ll mid = (le + ri) / 2;	// 이번 탐색에서의 금액
		ll cnt = 0, cur = 0;	// 몇 회 인출했는지, 현재 잔액

		for(int i = 0; i < n; i++) {
			if(mid < money[i]) {	// 최대금액 < 사용해야하는금액
				isover = true;
				break;
			}

			if(cur < money[i] || m - cnt == n - i) {
				// 1. 잔액이 부족한 경우 잔액 충전
				// 2. 정확히 M번을 맞추기 위해 다시 인출
				cnt++;
				cur = mid;
			} 

			cur = cur - money[i];
		}

		if(isover || m < cnt) {
			// 최대 잔고가 너무 낮은 경우, 더 많이 인출 한 경우
			// : 금액을 높여야 함
			le = mid + 1;
		} else if(m == cnt) {
			// 딱 맞게 인출 한 경우 : 저장 후 최소 금액이 존재하는지 확인
			k = mid;
			ri = mid - 1;
		} else {
			// 적게 인출 한 경우 : 금액을 낮춰야 함
			ri = mid - 1;
		}
	}

	cout << k << "\n";

	return 0;
}