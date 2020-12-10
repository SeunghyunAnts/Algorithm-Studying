/*
    BOJ 9421 (https://www.acmicpc.net/problem/9421)
*/

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

bool isPrime[1000000 + 1];
int powSum[1000000 + 1];

bool letstart = false;

int func(int num) {
	// num이 상근수인지 확인하는 함수.

	// cout << "cur num, powSum : " << num << " " << powSum[num] << "\n";
	
	if(powSum[num] == 1) {
		// 이전에 계산한 결과가 있을 경우 (상근수 o)
		return 1;
	} else if(powSum[num] == 0) {
		// 이전에 계산한 결과가 있을 경우 (상근수 x)
		return 0;
	} else if(powSum[num] == 2) {
		// 계산 중인 경우 -> 똑같은 수를 다시 탐색하므로, 무한 반복임.
		return powSum[num] = 0;
	}
	// 위의 경우가 아니면(-1인 경우) 탐색한 적이 없음.
	
	string numstr = to_string(num);
	int nextNum = 0;

	for(int i = 0; i < numstr.size(); i++) {
		int cur = (int)numstr[i] - (int)'0';
		nextNum += cur * cur;
	}

	powSum[num] = 2;		// 확인 중

	if(nextNum == 1) {
		// 상근수인 경우이므로 리턴
		return powSum[num] = 1;
	}

	// 상근수인지 확인하는 과정
	bool check = func(nextNum);

	if(check) {
		// 상근수인경우
		return powSum[num] = 1;
	} else {
		// 상근수가 아닌경우
		return powSum[num] = 0;
	}


}

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	memset(isPrime, 1, sizeof(isPrime));
	memset(powSum, -1, sizeof(powSum));

	isPrime[0] = isPrime[1] = false;
	powSum[1] = 1;

	// 먼저 소수를 걸러줌
	for(int i = 2; i < 1000000 + 1; i++) {
		if(!isPrime[i] || (i % 2 == 0 && i != 2)) {
			continue;
		} else {
			// i가 소수인 경우
			isPrime[i] = true;

			for(int j = 2; i * j < 1000000 + 1; j++) {
				if(isPrime[i * j]) {
					isPrime[i * j] = false;
				}
			}
		}
	}

	// 이후 상근수를 걸러줌
	for(int i = 1; i < n + 1; i++) {
		if(powSum[i] == -1) {
			// i번째 powSum을 탐색하지 않았다면
			bool isPS = func(i);
			if(isPS && isPrime[i]) {
				// 상근수이면서 소수이면 -> 소수상근수이므로 출력
				cout << i << "\n";
			}
		}
	}
	

	return 0;
}