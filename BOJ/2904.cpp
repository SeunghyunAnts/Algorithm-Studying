/*
    BOJ 15730 (https://www.acmicpc.net/problem/15730)
*/

#include <bits/stdc++.h>
#define minHeight 10001
#define maxHeight -1

typedef long long ll;

using namespace std;

bool isPrime[1000000 + 1];
vector<int> pNum;		// 1000000 이하의 78498 개의 소수
vector<int> pNumCnt;	// 78498 개의 소수가 나타난 횟수

void atos(void) {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = false;
	isPrime[1] = false;
	
	// 0번째 인덱스는 사용X
	pNum.push_back(-1);
	pNumCnt.push_back(-1);

	for(int i = 2; i < 1000000 + 1; i++) {
		if(!isPrime[i]) {
			continue;
		}

		pNum.push_back(i);		// i번째 소수
		pNumCnt.push_back(0);	// 입력받은 수를 분해했을 때, i번째 소수 개수

		for(int j = 2; i * j < 1000000 + 1; j++) {
			isPrime[i * j] = false;
		}
	}

	return;
}

int main(void) {

	int n, gcd = 1, move = 0;
	int arr[100] = {0};

	cin >> n;

	atos();

	for(int i = 0; i < n; i++) {
		cin >> arr[i];

		int cur = arr[i];

		for(int j = 1; j < pNum.size() && 1 < cur; j++) {
			// j번째 소수
			int PN = pNum[j];

			// 더이상 이번 소수로 나눌 수 없을 때 까지 반복
			while(cur % PN == 0) {
				cur = cur / PN;
				pNumCnt[j]++;	// 만약 나눠지면 해당 소수 개수 +1
			}
		}
	}

	// 1. GCD 계산
	for(int i = 1; i < pNumCnt.size(); i++) {
		int cnt = pNumCnt[i];
		
		if(0 < cnt / n) {
			// n개의 숫자에 i번째 소수를 1개 이상 분배 가능한 경우
			// gcd에 i번째 소수를 추가함.
			// cout << gcd  << " " << pNum[i] << " " << n << " " << cnt / n << "\n";

			gcd = gcd * (int)pow(pNum[i],(cnt / n));
			pNumCnt[i] = cnt / n;
		} else {
			// 1개 이상 분배 불가능한 경우
			pNumCnt[i] = 0;
		}
	}
	
	// 2. 몇 번 만에 점수를 얻을 수 있는지 계산
	for(int i = 0; i < n; i++) {
		int cur = arr[i];

		for(int j = 1; j < pNum.size(); j++) {
			if(pNumCnt[j] == 0) continue;
			// j번째 소수
			int PN = pNum[j];
			int curCnt = 0;

			// 이번 소수가 들어간 개수를 카운트
			while(cur % PN == 0) {
				cur = cur / PN;
				curCnt++;
			}

			

			// 필요한 개수만큼 move를 더해줌
			if(curCnt < pNumCnt[j]) {
				move += pNumCnt[j] - curCnt;
			}

			// cout << PN << " " << curCnt << " " << pNumCnt[j] << " " << move << "\n";
		}
	}

	cout << gcd << " " << move << "\n";

	return 0;
}