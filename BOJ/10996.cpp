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

	int n;
	cin >> n;
	for(int i = 0; i < 2 * n; i++) {
		if(i % 2 == 0) {
			for(int j = 0; j < n; j++) {
				if(j % 2 == 0) {
					cout << "*";
				} else {
					cout << " ";
				}
			}
		} else {
			for(int j = 0; j < n; j++) {
				if(j % 2 == 0) {
					cout << " ";
				} else {
					cout << "*";
				}
			}
		}
		cout << "\n";
	}

	return 0;
}