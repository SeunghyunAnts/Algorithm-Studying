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
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	for(int i = n - 1; i > 0; i--) {
		for(int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}