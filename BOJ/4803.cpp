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

	int n, m;

	for(int c = 1; ; c++) {
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		else cout << "Case " << c << ":";

		for(int i = 0; i < m; i++) {
			int n1, n2;
			cin >> n1 >> n2;


		}
	}

	return 0;
}