/*
    BOJ 1016 (https://www.acmicpc.net/problem/1016)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool isPrime[1000000 + 1];
vector<ll> pNum;

void atos(void) {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = false;
	isPrime[1] = false;

	for(int i = 2; i < 1000000 + 1; i++) {
		if(!isPrime[i]) continue;
		pNum.push_back(i);
		for(int j = 2; i * j < 1000000 + 1; j++) {
			isPrime[i * j] = false;
		}
	}

	return;
}

int main(void) {
	// 탐색할 범위 [l, h]
	ll l, h;

	// 탐색할 범위를 벡터로 표현
	vector<ll> v;

	// 제곱ㄴㄴ수 개수를 카운트
	int cnt = 0;

	// 입력
	cin >> l >> h;
	for(ll i = l; i <= h; i++) {
		v.push_back(i);
	}

	// 소수 구하기
	atos();

	for(int i = 0; i < pNum.size(); i++) {
		// 현재 반복문에서 계산할 소수의 제곱
		ll curPN2 = pNum[i] * pNum[i];
		
		// 현재 소수의 제곱에서 low값과 가장 인접한 배수를 탐색 (ll close)
		for(ll close = (l / curPN2) * curPN2; close <= h; close += curPN2) {
			if(0 <= close - l) {
				v[close - l] = -1;
			}
		}
	}

	for(int i = 0; i < v.size(); i++) {
		if(v[i] != -1) cnt++;
	}

	cout << cnt;

	return 0;
}