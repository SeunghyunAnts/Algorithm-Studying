/*
    BOJ 3896 (https://www.acmicpc.net/problem/3896)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int nums[1299709 + 1];		// 100000번째 소수까지의 숫자 배열
int between[1299709 + 1];	// 이전 소수 - 다음 소수 사이의 일반 수의 개수를 저장. 만약 between[k] 의 k가 일반수라면, 이전 값을 가지고 있음.

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int cnt = 0;	// 이전 소수부터 현재 소수까지 사이의 일반 수의 개수
	int tc, k;
	cin >> tc;

	for(int i = 2; i < 1299709 + 1; i++) {
		if(nums[i] == 0) {
			// 이전에 다른 수의 배수가 아니므로 소수이다.

			// 새로운 소수가 발견되었으므로, between값과 cnt값 변경
			between[i] = cnt;
			cnt = 0;

			for(int j = 2; i * j < 1299709 + 1; j++) {
				if(nums[i * j] == 0) {
					nums[i * j] = 1;
				}
			}
		} else {
			// 이전에 발견된 일반수이다.
			cnt++;
		}
	}

	while(tc--) {
		cin >> k;

		if(nums[k] == 0) {
			// 소수인 경우
			cout << 0;
			cout << "\n";
			continue;
		} else {
			// 일반 수인 경우
			for(int i = k; i < 1299709; i++) {
				if(nums[i + 1] == 0) {
					cout << between[i + 1] + 1;
					cout << "\n";
					break;
				}
			}
		}
	}

	return 0;
}