/*
    BOJ 6588 (https://www.acmicpc.net/problem/6588)
*/

#include <bits/stdc++.h>

#define MAX_NUM 1000000 + 1

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;

	// 탐색하여 false이면 소수
	bool isSearched[MAX_NUM];
	memset(isSearched, 0, sizeof(isSearched));
	
	// 0과 1은 소수가 아님
	isSearched[0] = true;
	isSearched[1] = true;

	for(int i = 2; i < (int)sqrt(MAX_NUM) + 1; i++) {
		if(isSearched[i] || (i % 2 == 0 && i != 2)) {
			// 이전에 방문했거나, 2가 아닌 짝수이면 확인할 필요 없음.
			continue;
		} else {
			// 이전에 방문하지 않았으므로, i는 소수
			for(int j = 2; i * j < MAX_NUM; j++) {
				// i가 소수이므로, i의 배수는 소수가 아님.
				if(!isSearched[i * j]) {
					// i의 배수 중 방문하지 않은 수를 방문처리
					isSearched[i * j] = true;
				}
			}
		}
	}

	while(true) {
		cin >> tc;
		if(tc == 0) break;
		
		bool isRight = false;
		int a = 0, b = 0;

		for(int i = 3; i < MAX_NUM; i++) {
			if(i > tc - i) break;
			if(isSearched[i] || isSearched[tc - i]) continue;	// 소수가 아니면 다음탐색
			else {
				isRight = true;
				a = i;
				b = tc - i;
				break;
			}
		}

		if(isRight) {
			cout << tc << " = " << a << " + " << b << "\n";
		} else {
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}

	return 0;
}