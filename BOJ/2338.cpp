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

	string a, b;
	cin >> a >> b;
	int aa, bb;
	
	if(a[0] == '0') {
		aa = 0;
	} else if(a[0] == '-') {
		aa = -1;
	} else {
		aa = 1;
	}

	if(b[0] == '0') {
		bb = 0;
	} else if(b[0] == '-') {
		bb = -1;
	} else {
		bb = 1;
	}

	cout << aa + bb << "\n" << aa - bb << "\n" << aa * bb;

	return 0;
}