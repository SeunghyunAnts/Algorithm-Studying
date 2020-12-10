#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수
int n;
ll cnt[10] = {0};

// 0이상 n이하의 모든 수에서 0 ~ 9가 몇 번 나오는지 확인하는 함수
void solve(int size, int startp, int endp) {
	int e = endp;
	string es = to_string(endp);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	string s = to_string(n);
	
	solve(s.size(), 0, n);

	for(int i = 0; i < 10; i++) cout << cnt[i] << " ";

	return 0;
}