/*
    BOJ 16561 (https://www.acmicpc.net/problem/16561)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k = 0;
	cin >> n;
	while(n > 1) {
		n /= 3;
		k++;
	}

	cout << (k - 2) * (k - 3) / 2;

	return 0;
}