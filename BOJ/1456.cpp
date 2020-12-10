/*
    BOJ 1456 (https://www.acmicpc.net/problem/1456)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll a, b, cnt = 0;	// a <= b <= 10^14, a와 b사이의 거의 소수 개수
	ll limitll = 10000000 * 10000000;
	vector<int> isPrime(10000000 + 1);
	vector<ll> primeNum;

	fill(isPrime.begin(), isPrime.end(), -1);
	isPrime[0] = 0;
	isPrime[1] = 0;

	cin >> a >> b;

	// 소수 체크
	for(int i = 2; i < 10000000 + 1; i++) {
		if(isPrime[i] == -1) {
			isPrime[i] = 1;
			primeNum.push_back((ll)i);

			for(int j = 2; i * j < 10000000 + 1; j++) {
				isPrime[i * j] = 0;
			}
		}	// else continue;
	}

	for(int i = 0; i < primeNum.size(); i++) {
		// 더이상 탐색하지 않아도 됨.
		if(primeNum[i] * primeNum[i] > b) {
			break;
		}

		// i의 제곱부터 검사해서 a와 b사이의 n제곱 개수를 찾음.
		ll cur = primeNum[i];
		while(primeNum[i] < b / cur) {
			if(a <= cur) {
				cnt++;
			}
			cur *= primeNum[i];
		}
	}

	cout << cnt;

	return 0;
}