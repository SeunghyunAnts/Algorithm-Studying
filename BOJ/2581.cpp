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

	int tc;
	bool primenumber[10000 + 1];
	cin >> tc;
	
	
	memset(primenumber, true, sizeof(primenumber));
	primenumber[1] = false;

	for(int i = 2; i < 10000 + 1; i++) {
		if(!primenumber[i]) continue;
		for(int j = 2; i * j < 10000 + 1; j++) {
			primenumber[i * j] = false;
		}
	}

	while(tc--) {
		int n;
		cin >> n;
		for(int i = n / 2; i >= 2; i--) {
			int j = n - i;
			if(primenumber[i] && primenumber[j]) {
				cout << i << " " << j << "\n";
				break;
			}
		}
	}

	return 0;
}