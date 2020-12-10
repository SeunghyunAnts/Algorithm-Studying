/*
    BOJ 1456 (https://www.acmicpc.net/problem/2591)
*/

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int ci(char c) {
	return (int)(c - '0');
}

int memo[40 + 1] = {0};	// memo[x] : idx x부터 끝까지 경우의 수

int solve(int i, string s) {
	if(s.size() <= i) {
		return 0;
	} else if(memo[i] != -1) {
		// 이전에 계산한 결과 있음.
		return memo[i];
	} else {
		// 이전에 계산한 결과 없음.
		memo[i] = 0;
		if(ci(s[i]) == 0) {
			// 현재 index의 값이 0이면 경우의 수 없음.
			return memo[i];
		}

		if(i == s.size() - 1) {
			// 마지막 자리인 경우 1~9가 들어오므로 1가지 경우
			memo[i] += 1;
		} else {
			// 그렇지 않으면, 경우의 수를 나눠서 생각
			if(ci(s[i]) * 10 + ci(s[i + 1]) <= 34) {
				// 두자리수가 가능한 경우
				memo[i] += solve(i + 1, s);	// 현재 한자리수
				memo[i] += solve(i + 2, s);	// 현재 두자리수
				if(i == s.size() - 2) memo[i]++;
			} else {
				// 두자리수가 불가능한 경우
				memo[i] += solve(i + 1, s);
			}
		}
	}

	return memo[i];
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int cnt = 0;	// 가능한 카드 배열의 수
	string num;		// 카드의 숫자를 적어놓은 것
	cin >> num;

	for(int i = 0; i < num.size(); i++) {
		memo[i] = -1;	// 방문 필요
	}
	
	solve(0, num);
	cout << memo[0];

	return 0;
}