#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 1, 0};
int diry[4] = {0, 1, 1};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, maxlen;
	cin >> n >> m;
	maxlen = min(n, m);
	vector<string> arr;
	for(int i = 0; i < n; i++) {
		string s; cin >> s; arr.push_back(s);
	}
	for(int size = maxlen; 0 < size; size--) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				bool issquare = true;
				for(int k = 0; k < 3; k++) {
					int y = i + diry[k] * (size - 1);
					int x = j + dirx[k] * (size - 1);
					if(0 <= x && x < m && 0 <= y && y < n) {
						if(arr[y][x] == arr[i][j]) {
							issquare = issquare && true;
						} else {
							issquare = false;
						}
					} else {
						issquare = false;
					}
				}
				if(issquare) {
					cout << size * size;
					return 0;
				}
			}
		}
	}

	return 0;
}