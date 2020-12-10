#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

int n10(int num10) {
	int i = 1000, cnt = 0;
	while(0 < i) {
		cnt += num10 / i;
		num10 = num10 % i;
		i = i / 10;
	}
	return cnt;
}

int n12(int num10) {
	int cnt = 0;
	while(0 < num10) {
		cnt += num10 % 12;
		num10 = num10 / 12;
	}
	return cnt;
}

int n16(int num10) {
	int cnt = 0;
	while(0 < num10) {
		cnt += num10 % 16;
		num10 = num10 / 16;
	}
	return cnt;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for(int i = 1000; i < 10000; i++) {
		if(n10(i) == n12(i) && n12(i) == n16(i)) {
			cout << i << "\n";
		}
	}

	return 0;
}