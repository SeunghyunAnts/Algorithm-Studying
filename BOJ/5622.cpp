#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))
// int pair 간단히
#define pii pair<int, int>
#define mp(X, Y) make_pair(X, Y)

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;

	int sum = 0;
	for(int i = 0; i < s.size(); i++) {
		sum += 1;
		if('A' <= s[i] && s[i] <= 'C') {
			sum += 2;
		} else if('D' <= s[i] && s[i] <= 'F') {
			sum += 3;
		} else if('G' <= s[i] && s[i] <= 'I') {
			sum += 4;
		} else if('J' <= s[i] && s[i] <= 'L') {
			sum += 5;
		} else if('M' <= s[i] && s[i] <= 'O') {
			sum += 6;
		} else if('P' <= s[i] && s[i] <= 'S') {
			sum += 7;
		} else if('T' <= s[i] && s[i] <= 'V') {
			sum += 8;
		} else if('W' <= s[i] && s[i] <= 'Z') {
			sum += 9;
		} else {
			continue;
		}
	}

	cout << sum;

	return 0;
}