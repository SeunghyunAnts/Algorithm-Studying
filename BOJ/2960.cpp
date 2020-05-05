/*
    BOJ 2960 (https://www.acmicpc.net/problem/2960)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int nums[1000 + 1];	// nums[k] 가 0이면 소수, 1이면 일반 수이다.

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	int cnt = 0;
	int kth_del_num = 0;

	cin >> n >> k;

	nums[0] = -1;	// 불가능
	nums[1] = 1;	// 1은 소수가 아니다

	for(int i = 2; i < n + 1; i++) {
		if(nums[i] == 1) {
			continue;
		}
		
		// k번째 수이면 해당 수를 출력하고 정지
		cnt++;
		kth_del_num = i;
	
		
		if(cnt == k) {
			cout << kth_del_num;
			break;
		}
		
		if(nums[i] == 0) {
			// 이전에 방문하지 않았으면, 해당 수는 소수이다.
			for(int j = 2; i * j < n + 1; j++) {
				// 소수의 배수는 소수가 아니다
				if(nums[i * j] == 1) continue;
				
				nums[i * j] = 1;
				
				cnt++;
				kth_del_num = i * j;
		
				if(cnt == k) {
					cout << kth_del_num;
					break;
				}
			}
		}
	}

	return 0;
}